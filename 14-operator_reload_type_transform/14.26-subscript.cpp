/* 2017.01.18 20:05
 * !!!
 * P_502
 * subscript operator: !!!
 * both const and non-const return value should be define
 * add:
 *	string& StrVec::operator[](size_t);
 * 	const string& StrVec::operator[](size_t) const;
 *	string& StrBlob::operator[](size_t);
 * 	const string& StrBlob::operator[](size_t) const;
 *	string& StrBlobPtr::operator[](size_t);
 * 	const string& StrBlobPtr::operator[](size_t) const;
 *	string& String::operator[](size_t);
 * 	const string& String::operator[](size_t) const;
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

/* StrVec */
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

/* StrBlob StrBlobPtr */
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
		friend bool operator==(const StrBlob&, const StrBlob&);
		friend bool operator!=(const StrBlob&, const StrBlob&);
		friend bool operator<(const StrBlob&, const StrBlob&);
		string& operator[](size_t);
		const string& operator[](size_t) const;
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
	return *this;
}
bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data == *rhs.data;
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data < *rhs.data;
}
string& StrBlob::operator[](size_t n)
{
	Check(n, "out of range");
	return data->at(n);
}
const string& StrBlob::operator[](size_t n) const
{
	Check(n, "out of range");
	return data->at(n);
}

class StrBlobPtr {
	public:
		StrBlobPtr(): curr(0) { }
		StrBlobPtr(StrBlob &a, size_t sz = 0):
			wptr(a.data), curr(sz) { }
		string & Deref() const;
		StrBlobPtr & Incr();
		friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
		friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
		friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
		string& operator[](size_t);
		const string& operator[](size_t) const;
	private:
		shared_ptr<vector<string>> Check(size_t, string const &) const;
		weak_ptr<vector<string>> wptr;
		size_t curr;
};
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return *lhs.wptr.lock() == *rhs.wptr.lock();
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.wptr.lock() < rhs.wptr.lock();
}
string& StrBlobPtr::operator[](size_t n)
{
	auto sptr = Check(n, "out of range");
	return sptr->at(n);
}
const string& StrBlobPtr::operator[](size_t n) const
{
	auto sptr = Check(n, "out of range");
	return sptr->at(n);
}
shared_ptr<vector<string>> StrBlobPtr::Check(size_t n, string const &msg) const
{
	shared_ptr<vector<string>> sptr = wptr.lock();
	if (sptr == nullptr)
		throw runtime_error("unbound weat_ptr");
	if (sptr->size() <= n)
		throw out_of_range(msg);
	return sptr;
}

/* String */
class String {
	public:
		String();
		String(const char*);
		String(const String&);
		String(String&&) noexcept;
		~String();
		String& operator=(const String&);
		String& operator=(String&&) noexcept;
		friend bool operator==(const String&, const String&);
		friend bool operator!=(const String&, const String&);
		friend bool operator<(const String&, const String&);
		char& operator[](size_t);
		const char& operator[](size_t) const;
		char* begin() const { return elements;}
		char* end() const { return first_free;}
		size_t size() const { return first_free - elements;}
	private:
		allocator<char> alloc;
		pair<char*, char*> alloc_n_copy(const char*, const char*);
		void free();
		char *elements;
		char *first_free;
		char *cap;
};
String::String(): elements(alloc.allocate(1))
{
	*elements = '\0';
	cap = first_free = elements + 1;
}
String::String(const String &s)
{
	pair<char*, char*> newData = alloc_n_copy(s.elements, s.first_free);
	elements = newData.first;
	cap = first_free = newData.second;
}
String::String(const char *cstrBeg)
{
	const char *cstrEnd = cstrBeg;
	while (*cstrEnd++ != '\0');
	first_free = elements = alloc.allocate(cstrEnd - cstrBeg);
	while (cstrBeg != cstrEnd)
		alloc.construct(first_free++, *cstrBeg++);
	cap = first_free;
}
String::~String()
{
	free();
}
String& String::operator=(const String &s)
{
	pair<char*, char*> newData = alloc_n_copy(s.elements, s.first_free);
	free();
	elements = newData.first;
	cap = first_free = newData.second;
	return *this;
}
pair<char*, char*> String::alloc_n_copy(const char *beg, const char *end)
{
	char *data = alloc.allocate(end - beg);
	return {data, uninitialized_copy(beg, end, data)};
}
void String::free()
{
	if (elements != nullptr && first_free != nullptr) {
		while (first_free != elements)
			alloc.destroy(--first_free);
		alloc.deallocate(elements, cap - elements);
		cap = first_free = elements = nullptr;
	}
}
String::String(String &&s) noexcept
: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	cout << "in String move-constructor" << endl;
	s.elements = s.first_free = s.cap = nullptr;
}
String& String::operator=(String &&s) noexcept
{
	cout << "in String move-assignment" << endl;
	if (this != &s) {
		free();
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		s.cap = s.first_free = s.elements = nullptr;
	}
	return *this;
}
bool operator==(const String &lhs, const String &rhs)
{
	bool result = true;
	size_t sizeLhs = lhs.size(), sizeRhs = rhs.size();
	char *dataLhs = lhs.begin(), *dataRhs = rhs.begin();
	if (sizeLhs == sizeRhs) {
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
bool operator!=(const String &lhs, const String &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const String &lhs, const String &rhs)
{
	bool result = true;
	char *dataLhs = lhs.begin(), *dataRhs = rhs.begin();
	while (*dataLhs != '\0' && *dataRhs != '\0') {
		if (*dataLhs >= *dataRhs)
			result = false;
	}
	if (result == true && lhs.size() >= rhs.size())
		result = false;
	return result;
}
char& String::operator[](size_t n)
{
	return elements[n];
}
const char& String::operator[](size_t n) const
{
	return elements[n];
}

int main(int argc, char **argv)
{

	return 0;
}
