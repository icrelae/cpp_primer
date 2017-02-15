/* 2017.02.15 21:43
 * P_517
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Integral {
	operator const int();	// const is meaningless
	operator int() const;	// not change the state of obj
};

int main(int argc, char **argv)
{

	return 0;
}

