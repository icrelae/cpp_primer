/* 2017.02.18 08:32
 * P_536
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base { };
class Derived: public Base { };

int main(int argc, char **argv)
{
	Derived derived;
	Base *pBase = &derived;	// static type: Base; dynamic type: Derived

	return 0;
}

