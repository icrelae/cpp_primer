/* 2017.03.18 15:45
 * P_603
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>
int compare(const T &lhs, const T &rhs)
{
	return lhs < rhs;
}

int main(int argc, char **argv)
{
	// a
	// invalid, args are 'T&', first 'T' is 'char[3]' but second is 'char[6]'
	compare("hi", "world");
	// b
	// valid, 'T' is 'char[4]'
	compare("bye", "dad");

	return 0;
}

