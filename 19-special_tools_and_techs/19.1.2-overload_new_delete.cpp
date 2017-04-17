/* 2017.04.17 21:59
 * P_729
 * void *operator new(size_t);
 * void *operator new[](size_t);
 * void *operator delete(size_t);
 * void *operator delete[](size_t);
 *
 * promise no throw
 * void *operator new(size_t, nothrow_t&);
 * void *operator new[](size_t, nothrow_t&);
 * void *operator delete(size_t, nothrow_t&);
 * void *operator delete[](size_t, nothrow_t&);
 *
 * nothrow_t: header <hew>, empty struct
 *
 * melloc() free(): header <cstdlib>
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

void *operator new(size_t size)
{
	if (void *mem = malloc(size))
		return mem;
	else
		throw bad_alloc();
}
void operator delete(void *mem) noexcept
{
	free(mem);
}

class StrVec {
	public:
		StrVec();
		StrVec(initializer_list<string>);
		StrVec(const StrVec&);
		~StrVec();
		StrVec(StrVec&&) noexcept;
		StrVec& operator=(const StrVec&);
		StrVec& operator=(StrVec&&) noexcept;
		friend bool operator==(const StrVec&, const StrVec&);
		friend bool operator!=(const StrVec&, const StrVec&);
		friend bool operator<(const StrVec&, const StrVec&);
		StrVec& operator=(initializer_list<string>);
		string& operator[](size_t);
		const string& operator[](size_t) const;
		void push_back(const string&);
		void push_back(string&&);
		string* begin() const { return elements;}
		string* end() const { return first_free;}
		size_t size() const { return first_free - elements;}
		size_t capacity() const { return cap - elements;}
		template<typename... Args> void emplace_back(Args&&...);
	private:
		void chk_n_alloc();
		pair<string*, string*> alloc_n_copy(const string*, const string*);
		void free();
		void reallocate();
		string *elements;
		string *first_free;
		string *cap;
};
StrVec::StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr)
{
}
StrVec::StrVec(initializer_list<string> lstStr)
{
	string *data = new string[lstStr.size()];
	elements = data;
	for (const auto &str : lstStr)
		*data++ = str;
	cap = first_free = data;
}
StrVec::StrVec(const StrVec &orig)
{
	pair<string*, string*> newData = alloc_n_copy(orig.elements, orig.first_free);
	elements = newData.first;
	cap = first_free = newData.second;
}
StrVec& StrVec::operator=(const StrVec &rhs)
{
	pair<string*, string*> newData = alloc_n_copy(rhs.elements, rhs.first_free);
	free();
	elements = newData.first;
	cap = first_free = newData.second;
	return *this;
}
StrVec::~StrVec()
{
	free();
}
void StrVec::push_back(const string &s)
{
	cout << "in lvalue push_back" << endl;
	chk_n_alloc();
	*first_free++ = s;
}
// rvalue reload member function !!!
void StrVec::push_back(string &&s)
{
	cout << "in rvalue push_back" << endl;
	chk_n_alloc();
	*first_free++ = std::move(s);
}
void StrVec::free()
{
	//while (first_free != elements)
	//	alloc.destroy(--first_free);

	//for_each(elements, first_free,
	//		[this] (string &s) {
	//			this->alloc.destroy(&s);
	//		});
	//alloc.deallocate(elements, cap - elements);
	delete[] elements;
	cap = first_free = elements = nullptr;
}
void StrVec::chk_n_alloc()
{
	if (size() == capacity())
		reallocate();
}
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	//string *data = alloc.allocate(e - b);
	string *data = new string[e - b];
	return {data, uninitialized_copy(b, e, data)};
}
void StrVec::reallocate()
{
	size_t newCapacity = size() == 0 ? 1 : size() * 2;
	//string *newData = alloc.allocate(newCapacity);
	string *newData = new string[newCapacity];
	// move iterator: *mit=rvalue !!!
	string *last = uninitialized_copy(make_move_iterator(begin()),
				make_move_iterator(end()), newData);
	free();
	elements = newData;
	first_free = last;
	cap = elements + newCapacity;
}
// move-construct: parameter is 'StrVec &&' !!!
// 'noexcept' need to be specified both in-class and out-class !!!
StrVec::StrVec(StrVec &&s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
	// here will destruct s !!!
}
StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}
bool operator==(const StrVec &lhs, const StrVec &rhs)
{
	if (&lhs == &rhs)
		return true;
	bool result = true;
	size_t sizeLhs = lhs.size(), sizeRhs = rhs.size();
	if (sizeLhs == sizeRhs) {
		string *dataLhs = lhs.begin(), *dataRhs = rhs.begin();
		for (size_t i = 0; i < sizeLhs; ++i) {
			if (*(dataLhs + i) != *(dataRhs + i)) {
				result = false;
				break;
			}
		}
	} else {
		result = false;
	}
	return result;
}
bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const StrVec &lhs, const StrVec &rhs)
{
	bool result = true;
	string *dataLhs = lhs.begin(), *dataRhs = rhs.begin();
	while (dataLhs != lhs.end() && dataRhs != rhs.end()) {
		if (*dataLhs++ >= *dataRhs++) {
			result = false;
			break;
		}
	}
	if (result == true && lhs.size() >= rhs.size())
		result = false;
	return result;
}
StrVec& StrVec::operator=(initializer_list<string> li)
{
	pair<string*, string*> newData = alloc_n_copy(li.begin(), li.end());
	free();
	elements = newData.first;
	cap = first_free = newData.second;
	return *this;
}
string& StrVec::operator[](size_t n)
{
	return elements[n];
}
const string& StrVec::operator[](size_t n) const
{
	return elements[n];
}
// '&&' keep origin type, 'forward' restore var origin type
template<typename... Args>
void StrVec::emplace_back(Args&&... args)
{
	chk_n_alloc();
	//alloc.construct(first_free++, std::forward<Args>(args)...);
	*first_free++ = string(std::forward<Args>(args)...);

}
void RvalueReloadEG()
{
	StrVec vec;
	string str = "asd";
	vec.push_back(str);
	vec.push_back("qwe");
	/* output:
	 *	in lvalue push_back
	 *	in rvalue push_back
	 */
}


int main(int argc, char **argv)
{
	StrVec vec;
	string str = "asdf";
	vec.emplace_back(10, 'A');
	vec.emplace_back(str);
	
	for_each(vec.begin(), vec.end(),
			[] (const string &str) {
				cout << str << ' ';
			});
	// output: AAAAAAAAAA asdf 

	return 0;
}

