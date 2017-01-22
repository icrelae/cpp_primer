/* 2017.01.18 20:05
 * P_504
 *
 * need to change state of obj
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
class StrBlob {
	public:
		StrBlob();
		StrBlob(const StrBlob&);
		StrBlob(initializer_list<string> il);
		StrBlob& operator=(const StrBlob&);
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
		void Check(size_t, const string&) const;
};
StrBlob::StrBlob(): data(make_shared<vector<string>>())
{
}
StrBlob::StrBlob(const StrBlob &orig): data(make_shared<vector<string>>(*orig.data))
{
}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il))
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
string& StrBlob::front()
{
	Check(0, "front on empty StrBlob");
	return data->front();
}
string& StrBlob::back()
{
	Check(0, "back on empty StrBlob");
	return data->back();
}
void StrBlob::pop_back()
{
	Check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
void StrBlob::pop_back() const
{
	Check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
string const & StrBlob::front() const
{
	Check(0, "const front on empty StrBlob");
	return const_cast<string const &>(data->front());
}
string const & StrBlob::back() const
{
	Check(0, "const back on empty StrBlob");
	return const_cast<string const &>(data->back());
}
void StrBlob::Check(size_t i, const string &msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

class StrBlobPtr {
	public:
		StrBlobPtr(): curr(0) { }
		StrBlobPtr(StrBlobPtr& a): wptr(a.wptr), curr(a.curr) { }
		StrBlobPtr(StrBlobPtr& a, size_t x): wptr(a.wptr), curr(x) { }
		StrBlobPtr(StrBlob &a, size_t sz = 0):
			wptr(a.data), curr(sz) { }
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
		StrBlobPtr operator+(int);
		StrBlobPtr operator-(int);
	public:
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
StrBlobPtr& StrBlobPtr::operator++()
{
	++curr;
	Check(curr, "increment past end of StrBlobPtr");
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
StrBlobPtr StrBlobPtr::operator+(int n)
{
	Check(curr + n, "adding out of range");
	StrBlobPtr ret(*this, curr + n);
	return ret;
}
StrBlobPtr StrBlobPtr::operator-(int n)
{
	Check(curr - n, "adding out of range");
	StrBlobPtr ret(*this, curr - n);
	return ret;
}

int main(int argc, char **argv)
{
	StrBlob sb({"asdfdsa", "asd", "adsf", "as", "asd", "asd", "as"});
	StrBlobPtr sbp(sb);
	cout << sbp+1 << ' ';
	cout << sbp.curr << ' ';
	cout << sbp-1 << ' ';
	cout << sbp.curr << ' ';
	// output: 0 1 1 2 3 3 4 4 

	return 0;
}
