/* 2016.09.24 19:59
 * P_128
 * i < k return a bool, which cast to int
 * then check whether equals to i
 */
#include <iostream>

int main(int argc, char **argv)
{
	int i = 1, j = 2, k1 = 0, k2 = 10;
	if (i != j < k1)
		std::cout << "1 true" << std::endl;
	if (i != j < k2)
		std::cout << "2 true" << std::endl;

	return 0;
}

