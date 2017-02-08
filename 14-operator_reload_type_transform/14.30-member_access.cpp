/* 2017.02.08 21:07
 * P_506
 * add:
 *	string& StrBlobPtr::operator*()
 * 	string* StrBlobPtr::operator->()
 * 	const string& ConstStrBlobPtr::operator*() const
 * 	string const * ConstStrBlobPtr::operator->() const
 *
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

/* StrBlob StrBlobPtr */
class StrBlobPtr;
class ConstStrBlobPtr;

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
		ConstStrBlobPtr begin() const;
		ConstStrBlobPtr end() const;
	private:
		friend class StrBlobPtr;
		friend class ConstStrBlobPtr;
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
		StrBlobPtr(const StrBlobPtr& sbPtr):
			wptr(sbPtr.wptr), curr(sbPtr.curr) { }
		string & Deref() const;
		StrBlobPtr & Incr();
		friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
		friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
		friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
		string& operator[](size_t);
		const string& operator[](size_t) const;
		StrBlobPtr& operator++();
		StrBlobPtr& operator--();
		StrBlobPtr operator++(int);
		StrBlobPtr operator--(int);
		friend StrBlobPtr operator+(const StrBlobPtr&, int);
		friend StrBlobPtr operator-(const StrBlobPtr&, int);
		string& operator*();
		string* operator->();
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
StrBlobPtr& StrBlobPtr::operator++()
{
	Check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
StrBlobPtr& StrBlobPtr::operator--()
{
	--curr;
	Check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}
StrBlobPtr StrBlobPtr::operator++(int)
{
	StrBlobPtr ret = *this;
	++*this;
	return ret;
}
StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr ret = *this;
	--*this;
	return ret;
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
StrBlobPtr operator+(const StrBlobPtr& sbPtr, int increment)
{
	StrBlobPtr ret(sbPtr);
	ret.curr += increment;
	ret.Check(ret.curr, "increment past end of StrBlobPtr");
	return ret;
}
StrBlobPtr operator-(const StrBlobPtr& sbPtr, int decrement)
{
	StrBlobPtr ret(sbPtr);
	ret.curr -= decrement;
	ret.Check(ret.curr, "decrement past end of StrBlobPtr");
	return ret;
}
string& StrBlobPtr::operator*()
{
	shared_ptr<vector<string>> p = Check(curr, "dereference past end");
	return p->at(curr);
}
string* StrBlobPtr::operator->()
{
	return &(this->operator*());
}

class ConstStrBlobPtr {
	public:
		ConstStrBlobPtr(): curr(0) { }
		ConstStrBlobPtr(StrBlob &a, size_t sz = 0):
			wptr(a.data), curr(sz) { }
		ConstStrBlobPtr(StrBlob const &a, size_t sz = 0):
			wptr(a.data), curr(sz) { }
		const string & Deref() const;
		ConstStrBlobPtr & Incr();
		const string& operator*() const;
		string const * operator->() const;
	private:
		shared_ptr<vector<string>> Check(size_t, string const &) const;
		weak_ptr<vector<string>> wptr;
		size_t curr;
};
shared_ptr<vector<string>> ConstStrBlobPtr::Check(size_t i, string const &msg) const
{
	auto sptr = wptr.lock();
	if (sptr == NULL)
		throw runtime_error("unbound ConstStrBlobPtr");;
	if (i >= sptr->size())
		throw out_of_range(msg);
	return sptr;
}
const string & ConstStrBlobPtr::Deref() const
{
	auto sptr = Check(curr, "Dereference of ConstStrBlobPtr");
	return sptr->at(curr);
}
ConstStrBlobPtr & ConstStrBlobPtr::Incr()
{
	Check(curr, "increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}
const string& ConstStrBlobPtr::operator*() const
{
	shared_ptr<vector<string>> p = Check(curr, "Dereference past end");
	return p->at(curr);
}
string const * ConstStrBlobPtr::operator->() const
{
	return &(this->operator*());
}

ConstStrBlobPtr StrBlob::begin() const
{
	return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::end() const
{
	return ConstStrBlobPtr(*this, data->size());
}

int main(int argc, char **argv)
{

	return 0;
}
