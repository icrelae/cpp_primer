/* 2016.10.16 15:04
 * P_217
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void f();			// 1
void f(int);			// 2
void f(int, int);		// 3
void f(double, double = 3.14);	// 4


int main(int argc, char **argv)
{
	// a: 4
	f(2.56, 42);
	// b: 2
	f(42);
	// c: 3
	f(42, 0);
	// d: 4
	f(2.56, 3.15);

	return 0;
}

