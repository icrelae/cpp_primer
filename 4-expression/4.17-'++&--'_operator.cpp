/* 2016.09.24 20:58
 * P_133
 */
#include <iostream>

int main(int argc, char **argv)
{
	int a, b;
	a = b = 0;

	std::cout << a++ << ' ';	// 0
	std::cout << a << std::endl;	// 1

	std::cout << ++b << ' ';	// 1
	std::cout << b << std::endl;	// 1



	return 0;
}

