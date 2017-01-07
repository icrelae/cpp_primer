/* 2017.01.07 21:01
 * P_444
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
		HasPtr & operator =(HasPtr const orig);
		~HasPtr() { delete ps; ps = NULL;}
	public:
		string *ps;
		int i;
};
HasPtr & HasPtr::operator =(HasPtr const orig)
{
	delete ps;
	ps = new string(*orig.ps);
	i = orig.i;
	return *this;
}

int main(int argc, char **argv)
{
	HasPtr a("asd"), b;
	b = a;
	cout << *b.ps;
	// output: asd

	return 0;
}

