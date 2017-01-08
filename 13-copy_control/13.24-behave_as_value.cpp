/* 2017.01.07 21:01
 * P_454
 *
 * memory leak
 * multi delete
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr {
	public:
		HasPtr(string const &s = string()):
			ps(new string(s)), i(0) { }
		HasPtr(HasPtr const &orig):
			ps(new string(*orig.ps)), i(orig.i) { }
		HasPtr & operator =(HasPtr const &orig);
		~HasPtr() { delete ps; ps = NULL;}
	public:
		string *ps;
		int i;
};
HasPtr & HasPtr::operator =(HasPtr const &orig)
{
	string *pStr = new string(*orig.ps);
	delete ps;
	ps = pStr;
	i = orig.i;
	return *this;
}

int main(int argc, char **argv)
{

	return 0;
}

