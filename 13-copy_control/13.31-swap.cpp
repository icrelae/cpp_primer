/* 2017.01.09 09:27
 * P_460
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr {
	public:
		HasPtr(const string &s = string());
		HasPtr(const HasPtr&);
		HasPtr& operator=(HasPtr);
		~HasPtr();
		bool operator<(const HasPtr&);
		void swap(HasPtr&);
	public:
		string *ps;
		unsigned *use;
};
HasPtr::HasPtr(const string &s): ps(new string(s)), use(new unsigned(1))
{
}
HasPtr::HasPtr(const HasPtr &h):
	ps(new string(*h.ps)), use(new unsigned(*h.use))
{
}
HasPtr& HasPtr::operator=(HasPtr rhs)
{
	this->swap(rhs);
	return *this;
}
HasPtr::~HasPtr()
{
	delete ps; ps = NULL;
	delete use; use = NULL;
}
bool HasPtr::operator<(const HasPtr &rhs)
{
	return *ps < *rhs.ps;
}
void HasPtr::swap(HasPtr &rhs)
{
	cout << "swap: ";
	cout << *this->ps << " | ";
	cout << *rhs.ps << " | " << endl;
	std::swap(this->ps, rhs.ps);
	std::swap(this->use, rhs.use);
}
void swap(HasPtr &lhs, HasPtr &rhs)
{
	cout << "double par swap" << endl;
	lhs.swap(rhs);
}

int main(int argc, char **argv)
{
	vector<HasPtr> vecHas{HasPtr("c"), HasPtr("b"), HasPtr("a")};
	// sort() using member-swap !!!
	sort(vecHas.begin(), vecHas.end());
	for (const auto hasp : vecHas)
		cout << *hasp.ps << ' ';
	/* output:
	 *	swap: b | c | 
	 *	swap: c | b | 
	 *	swap: a | c | 
	 *	swap: c | b | 
	 *	swap: b | a | 
	 *	a b c 
	 */

	return 0;
}

