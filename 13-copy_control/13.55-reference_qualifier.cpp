/* 2017.01.14 08:26
 * P_485
 * !!!
 * reference qualifier: !!!
 *	void memberFunc() &;		// *this have to be 'lvalue'
 * 	void memberFunc() &&;	// *this have to be 'rvalue'
 * 	void memberFunc() const &;	// *this have to be 'const lvalue'
 * 	void memberFunc() const &&;	// *this have to be 'const rvalue'
 * 	// const have to be in front of &;
 *	// for all member functions that have the same name and parameter list,
 *	// one have reference qualifier, all should have
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

class StrVec {
	public:
		StrVec();
		StrVec(initializer_list<string>);
		StrVec(const StrVec&);
		StrVec(StrVec&&) noexcept;
		StrVec& operator=(const StrVec&);
		StrVec& operator=(StrVec&&) noexcept;
		~StrVec();
		void push_back(const string&);
		void push_back(string&&);
		string* begin() const { return elements;}
		string* end() const { return first_free;}
		size_t size() const { return first_free - elements;}
		size_t capacity() const { return cap - elements;}
	private:
		void chk_n_alloc();
		pair<string*, string*> alloc_n_copy(const string*, const string*);
		void free();
		void reallocate();
		allocator<string> alloc;
		string *elements;
		string *first_free;
		string *cap;
};
StrVec::StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr)
{
}
StrVec::StrVec(initializer_list<string> lstStr)
{
	string *data = alloc.allocate(lstStr.size());
	elements = data;
	for (const auto &str : lstStr)
		alloc.construct(data++, str);
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
	alloc.construct(first_free++, s);
}
// rvalue reload member function !!!
void StrVec::push_back(string &&s)
{
	cout << "in rvalue push_back" << endl;
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}
void StrVec::free()
{
	//while (first_free != elements)
	//	alloc.destroy(--first_free);
	for_each(elements, first_free,
			[this] (string &s) {
				this->alloc.destroy(&s);
			});
	alloc.deallocate(elements, cap - elements);
	cap = first_free = elements = nullptr;
}
void StrVec::chk_n_alloc()
{
	if (size() == capacity())
		reallocate();
}
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	string *data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}
void StrVec::reallocate()
{
	size_t newCapacity = size() == 0 ? 1 : size() * 2;
	string *newData = alloc.allocate(newCapacity);
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

class StrBlobPtr;
class StrBlob {
	public:
		StrBlob();
		StrBlob(const StrBlob&);
		StrBlob& operator=(const StrBlob&);
		StrBlob(initializer_list<string> il);
		typedef vector<string>::size_type size_type;
		bool empty() const {return data->empty();}
		size_type size() const {return data->size();}
		void push_back(string const &str) { data->push_back(str);}
		void push_back(string const &&str) { data->push_back(std::move(str));}
		void pop_back();
		void pop_back() const;
		string& front();
		string& back();
		string const & front() const;
		string const & back() const;
		StrBlobPtr begin();
		StrBlobPtr end();
	private:
		friend class StrBlobPtr;
		shared_ptr<vector<string>> data;
		void Check(size_type i, string const &msg) const;
};
StrBlob::StrBlob(const StrBlob &orig): data(make_shared<vector<string>>(*orig.data))
{
}
StrBlob& StrBlob::operator=(const StrBlob &orig)
{
	data = make_shared<vector<string>>(*orig.data);
}
class StrBlobPtr {
	public:
		StrBlobPtr(): curr(0) { }
		StrBlobPtr(StrBlob &a, size_t sz = 0):
			wptr(a.data), curr(sz) { }
		string & Deref() const;
		StrBlobPtr & Incr();
	private:
		shared_ptr<vector<string>> Check(size_t, string const &) const;
		weak_ptr<vector<string>> wptr;
		size_t curr;
};

int main(int argc, char **argv)
{

	return 0;
}

