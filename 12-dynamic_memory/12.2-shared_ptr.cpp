/* 2016.12.29 08:35
 * P_407
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
StrBlob::StrBlob(): data(make_shared<vector<string>>()) {};
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {};
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
	StrBlob const b;
	b.front();
	/* output: 
	 *	terminate called after throwing an instance of 'std::out_of_range'
	 *	  what():  const front on empty StrBlob
	 */

	return 0;
}

