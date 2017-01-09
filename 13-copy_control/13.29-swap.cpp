/* 2017.01.09 09:27
 * P_460
 * !!!
 *
 * type of arguments are different
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
		HasPtr& operator=(HasPtr rhs);
		~HasPtr() { delete ps; ps = NULL;}
	public:
		string *ps;
		unsigned *use;
};
void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.use, rhs.use);
}
/* 'copy and swap' for '=' !!!
 * passing value rather than reference to copy rhs, than swap with *this,
 * after '=', rhs will be destruct;
 * copy before assignment keep it correct when self-assignment, so it's
 * self-assignment safe;
 * exception can only happen when passing argument 'rhs' which before change
 * 'lhs', so it's exception-safe as well;
 */
HasPtr& HasPtr::operator=(HasPtr rhs)
{
	swap(*this, rhs);
	return *this;
}

class Foo {
	public:
		HasPtr hasPtr;
};
void swap(Foo &lhs, Foo &rhs)
{
	/* !!!
	 * wrong, this will using std::swap rather than custom swap
	 * using swap instead of std::swap for custom operation
	 */
	std::swap(lhs.hasPtr, rhs.hasPtr);
}
void SwapEG()
{

}

int main(int argc, char **argv)
{

	return 0;
}

