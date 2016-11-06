/* 2016.09.25 13:17
 * P_140
 */
#include <iostream>

int main(int argc, char **argv)
{
	int x[10], *p = x;
	std::cout << sizeof(x) / sizeof(*x) << std::endl;	// 10
	std::cout << sizeof(p) / sizeof(*p) << std::endl;	// 2

	return 0;
}

