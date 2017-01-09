/* 2017.01.09 09:27
 * P_460
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr {
	public:
		HasPtr(const string &s = string());
		HasPtr(const HasPtr &orig);
		HasPtr& operator=(HasPtr rhs);
		~HasPtr() { delete ps; ps = NULL;}
	public:
		string *ps;
		unsigned *use;
};
HasPtr::HasPtr(const string &s): ps(new string(s)), use(new unsigned(1))
{
}
HasPtr::HasPtr(const HasPtr &orig):
	ps(new string(*orig.ps)), use(new unsigned(*orig.use))
{
}
void swap(HasPtr &lhs, HasPtr &rhs)
{
	cout << "swap: ";
	cout << *lhs.ps << " | ";
	cout << *rhs.ps << " | " << endl;
	swap(lhs.ps, rhs.ps);
	swap(lhs.use, rhs.use);
}
HasPtr& HasPtr::operator=(HasPtr rhs)
{
	swap(*this, rhs);
	return *this;
}

int main(int argc, char **argv)
{
	HasPtr a("aaa"), b("bbb"), c;
	swap(a, b);
	c = a;
	cout << "a: " << *a.ps << endl;
	cout << "b: " << *b.ps << endl;
	cout << "c: " << *c.ps << endl;
	/* output:
	 *	swap: aaa | bbb | 
	 *	swap:  | bbb | 
	 *	a: bbb
	 *	b: aaa
	 *	c: bbb
	 */

	return 0;
}

