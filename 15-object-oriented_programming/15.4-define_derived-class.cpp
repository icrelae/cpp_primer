/* 2017.02.17 08:38
 * P_533
 * override: !!!
 *		explicitly claim override virtual func from base class
 *		place at last in declaration
 * static: !!!
 *		if define a static member in base class, all derived class
 *		sharing this one
 * final: !!!
 *		prevent from be inherited
 *		place after class name
 *			class Name final { };
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// when using some class for base, it have to be complete defined rather than just declaration !!!
class Base;
class Derived: public Base { };	// wrong

class Base { };
// a, wrong; can't inherit from itself
class Derived1 : public Derived1 { };
// b, correct
class Derived2 : private Base { };
// c, wrong; shouldn't using inherit list in declaration
class Derived3 : public Base;

int main(int argc, char **argv)
{

	return 0;
}

