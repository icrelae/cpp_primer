/* 2017.01.07 21:01
 * P_444
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
		void push_back(string const &str) const { data->push_back(str);}
		void pop_back();
		void pop_back() const;
		string& front();
		string& back();
		string const & front() const;
		string const & back() const;
	private:
		friend class StrBlobPtr;
		shared_ptr<vector<string>> data;
		void Check(size_type i, string const &msg) const;
};
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

