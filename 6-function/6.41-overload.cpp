/* 2016.10.16 14:13
 * P_213
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char *init(int ht, int wd = 80, char bckgrnd = ' ');

int main(int argc, char **argv)
{
	// a: invalid
	init();
	// b: valid
	init(24, 10);
	// c: invalid
	init(14, '*');

	return 0;
}

