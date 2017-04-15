/* 2017.04.15 21:00
 * P_714
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class A { };
class B: public A { };
class C: public B { };
class X { };
class Y { };
class Z: public X, public Y { };
class MI: public C, public Z { };
class D: public X, public C { };

int main(int argc, char **argv)
{
	D *pd = new D;

	// all valid
	X *px = pd;
	A *pa = pd;
	B *pb = pd;
	C *pc = pd;

	return 0;
}

