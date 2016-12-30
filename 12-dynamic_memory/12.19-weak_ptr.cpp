/* 2016.12.30 11:40
 * P_422
 * !!!
 * weak_ptr: !!!
 *	shared with sptr, but don't increase reference count
 * operations of weak_ptr: !!!
 * weak_ptr<T> w
 * weak_ptr<T> w(sp): point to sp
 * w = p: p could be sptr or wptr
 * w.reset(): set w empty
 * w.use_count()
 * w.expired: if w.use_count()==0 return true, else return false
 * w.lock():
 *	if expired() true, return empty shared_ptr
 *	else return shared_ptr point to obj of w
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void WeakptrEG()
{
	weak_ptr<int> wp0 = make_shared<int>(42);
	weak_ptr<int> wp1(make_shared<int>(42));
	// no match for '*wp', because it meybe non-exist(already destroyed) !!!
	//cout << *wp1 << endl; // invalid
	shared_ptr<int> sptr = wp1.lock();
	if (sptr != NULL)
		cout << *sptr << endl;
}

class StrBlobPtr;

class StrBlob {
	public:
		StrBlob();
		StrBlob(initializer_list<string> il);
		typedef vector<string>::size_type size_type;
		bool empty() const {return data->empty();}
		size_type size() const {return data->size();}
		void push_back(string const &str) { data->push_back(str);}
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
StrBlob::StrBlob(): data(make_shared<vector<string>>())
{
}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il))
{
}
void StrBlob::Check(size_type i, string const &msg) const
{
	if (i >= this->size())
		throw out_of_range(msg);
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
shared_ptr<vector<string>> StrBlobPtr::Check(size_t i, string const &msg) const
{
	auto sptr = wptr.lock();
	if (sptr == NULL)
		throw runtime_error("unbound StrBlobPtr");;
	if (i >= sptr->size())
		throw out_of_range(msg);
	return sptr;
}
string & StrBlobPtr::Deref() const
{
	auto sptr = Check(curr, "Dereference of StrBlobPtr");
	return sptr->at(curr);
}
StrBlobPtr & StrBlobPtr::Incr()
{
	Check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

int main(int argc, char **argv)
{
	StrBlob sb{"a", "b", "c"};
	StrBlobPtr sbpBeg = sb.begin();
	cout << sbpBeg.Deref();
	// output: a

	return 0;
}

