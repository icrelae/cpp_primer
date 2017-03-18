/* 2017.03.18 16:01
 * P_603
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T> T calc(T, int);
template<typename T> T fcn(T, T);

int main(int argc, char **argv)
{
	double d;
	float f;
	char c;

	// a
	calc(c, 'c');
	// b
	calc(d, f);
	// c
	fcn(c, 'c');
	// d, invalid
	fcn(d, f);

	return 0;
}

