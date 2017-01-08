/* 2017.01.07 21:01
 * P_457
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr {
	public:
		HasPtr();
		HasPtr(string const &s = string());
		HasPtr(HasPtr const &orig);
		HasPtr & operator =(HasPtr const &orig);
		~HasPtr() { delete ps; ps = NULL;}
	public:
		string *ps;
		unsigned *use;
};
HasPtr::HasPtr(): ps(new string()), use(new unsigned(1))
{
}
HasPtr::HasPtr(string const &s): ps(new string(s)), use(new unsigned(1))
{
}
HasPtr::HasPtr(HasPtr const &orig): ps(orig.ps), use(orig.use)
{
	++(*use);
}
HasPtr& HasPtr::operator=(HasPtr const &orig)
{
	++*orig.use;
	if (--*use == 0) {
		delete ps;
		ps = NULL;
		delete use;
		use = NULL;
	}
	ps = orig.ps;
	use = orig.use; 
	return *this;
}

int main(int argc, char **argv)
{

	return 0;
}

