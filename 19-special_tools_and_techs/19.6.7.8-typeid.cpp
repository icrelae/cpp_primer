/* 2017.04.19 21:29
 * P_733
 * !!!
 * RTTI: run-time type identification: !!!
 * typeid(e): header <type_info>
 *	ignore top const
 *	won't cast array into pointer
 *	if 'e' is 'nullptr', throw exception 'bad_typeid'
 *	whether value 'e' depends on if 'e' has virtual function
 */
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Base {
	virtual void Show() { }
};
class Derived: public Base {
	void Show() { }
};

int main(int argc, char **argv)
{
	Derived derived, *dp;
	Base base, *bp;
	// ex 19.6
	bp = &base;
	dp = dynamic_cast<Derived*>(bp);
	if (nullptr != dp)
		cout << "base* > derived*: successed" << endl;
	else
		cout << "base* > derived*: failed" << endl;
	bp = &derived;
	dp = dynamic_cast<Derived*>(bp);
	if (nullptr != dp)
		cout << "base* > derived*: successed" << endl;
	else
		cout << "base* > derived*: failed" << endl;

	// ex 19.7
	Base &br1 = base;
	try {
		Derived &dr = dynamic_cast<Derived&>(br1);
		cout << "base& > derived&: successed" << endl;
	} catch (bad_cast) {
		cout << "base& > derived&: failed" << endl;
	}
	Base &br2 = derived;
	try {
		Derived &dr = dynamic_cast<Derived&>(br2);
		cout << "base& > derived&: successed" << endl;
	} catch (bad_cast) {
		cout << "base& > derived&: failed" << endl;
	}

	// ex 19.8
	bp = &derived;
	dp = dynamic_cast<Derived*>(bp);
	if (typeid(*bp) == typeid(*dp)) {
		cout << "same type, ";
		if (typeid(*bp) == typeid(Derived))
			cout << "is derived" << endl;
		else
			cout << "isn't derived" << endl;
	} else {
		cout << "different type" << endl;
	}
	/* output:
	 *	base* > derived*: failed
	 *	base* > derived*: successed
	 *	base& > derived&: failed
	 *	base& > derived&: successed
	 *	same type, is derived
	 */

	return 0;
}
