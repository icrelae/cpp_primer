/* 2017.04.15 21:00
 * P_713
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CAD { };
class Vehicle { };
class CADVehicle: public CAD, Vehicle { };
class List { };
//class DblLIst: public List, public List { };
class _iostream: public istream, public ostream { };

class A { };
class B: public A { };
class C: public B { };
class X { };
class Y { };
class Z: public X, public Y { };
class MI: public C, public Z { };

int main(int argc, char **argv)
{
	MI mi;
	// A B C X Y Z MI

	return 0;
}

