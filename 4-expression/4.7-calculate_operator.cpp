/* 2016.09.24 17:34
 * P_126
 */
#include <iostream>

int main(int argc, char **argv)
{
	unsigned char a = 255;
	unsigned int b = 0;
	int c = 2147483647;

	std::cout << (int)a << '\t';
	++ a;
	std::cout << (int)a << std::endl;

	std::cout << b << '\t' << b-1 << std::endl;

	std::cout << c << '\t' << c+1 << std::endl;

	return 0;
}

/* output:
 * 255	0
 * 0	4294967295
 * 2147483647	-2147483648
 */

