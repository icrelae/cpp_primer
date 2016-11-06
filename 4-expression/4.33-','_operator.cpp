/* 2016.09.25 15:25
 * P_141
 */
#include <iostream>

int main(int argc, char **argv)
{
	int x = 0, y = 0;

	x > y ? ++x, ++y : --x, --y;

	// if x > y, ++x ++y
	// else, --x --y

	return 0;
}

