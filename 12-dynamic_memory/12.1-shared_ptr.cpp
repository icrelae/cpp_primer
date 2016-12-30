/* 2016.12.29 08:35
 * P_406
 * !!!
 * smart pointer: !!!
 * head file: <memory>
 * categories: shared_ptr unique_ptr weak_ptr
 * operations for both shared_ptr and unique_ptr:
 *	shared_ptr<T> sp
 *	unique_ptr<T> up
 *	p, *p, p->member
 *	p.get(): return pointer stored in p
 *	swap(p, q):
 *	p.swap(q): swap pointer of p and q
 * operations for shared_ptr:
 *	make_shared<T>(args):
 *		return a shared_ptr point to an object of type T
 *		initialize with args
 *	shared_ptr<T> p(q):
 *		p is a copy of q, increase reference count of q
 *		q must be convertible to T*
 *	p = q:
 *		both p and q are shared_ptr, inner pointer should be convertible
 *		decreasing reference count of p and increasing q
 *		if reference count of p become 0, release it
 *	p.unique():
 *		if reference count of p is 1 then return true, else return false
 *	p.use_cout():
 *		return number of ptrs sharing with p
 *		maybe very slow, using for debug generally
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class StrBlob {
	public:
		StrBlob();
		StrBlob(initializer_list<string> il);
		typedef vector<string>::size_type size_type;
		bool empty() const {return data->empty();}
		size_type size() const {return data->size();}
		void push_back(string const &str) { data->push_back(str);}
		void pop_back() { data->pop_back();}
		string& front();
		string& back();
		string const & front() const;
		string const & back() const;
	private:
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

int main(int argc, char **argv)
{
	StrBlob b1;
	{
		StrBlob b2 = {"a", "an", "the"};
		b1 = b2;
		b2.push_back("about");
		cout << b1.size() << ' ';
		cout << b2.size() << ' ';
		// output: 4 4
	}
	cout << b1.size() << ' ';
	// out of scope of effect, already distruct
	//cout << b2.size() << ' ';

	// output: 4

	return 0;
}

