/* 2016.09.24 17:16
 * P_126
 */
#include <iostream>

int main(int argc, char **argv)
{
	std::cout << -30 * 3 + 21 / 5 << " = ";
	std::cout << -86 << std::endl;

	std::cout << -30 + 3 * 21 / 5 << " = ";
	std::cout << -18 << std::endl;

	std::cout << 30 / 3 * 21 % 5 << " = ";
	std::cout << 0 << std::endl;

	std::cout << -30 / 3 * 21 % 4 << " = ";
	std::cout << -2 << std::endl;

	return 0;
}

