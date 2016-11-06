/* 2016.09.20 22:15
 * P_116
 * dispay multiple dimension array using alia of type
 */
#include <iostream>

using MulDimArray4 = int[4];

int main(int argc, char **argv)
{
	int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};

	for (MulDimArray4 &i : ia)
		for (int const &j : i)
			std::cout << j << ' ';
	std::cout << std::endl;

	for (MulDimArray4 *i = ia; i < std::end(ia); ++ i)
		for (int *j = *i; j < std::end(*i); ++ j)
			std::cout << *j << ' ';
	std::cout << std::endl;

	return 0;
}
