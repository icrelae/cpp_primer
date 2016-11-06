/* 2016.10.16 15:04
 * P_217
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void f()			// 1
{
	cout << 1 << endl;
}
void f(int)			// 2
{
	cout << 2 << endl;
}
void f(int a, int b)		// 3
{
	cout << 3 << endl;
}
void f(double a, double b = 3.14)	// 4
{
	cout << 4 << endl;
}


int main(int argc, char **argv)
{
	// a: 4 error!!!
	// ambiguous between f(int, int) and f(double, double)
	f(2.56, 42);
	// b: 2
	f(42);
	// c: 3
	f(42, 0);
	// d: 4
	f(2.56, 3.15);

	return 0;
}

