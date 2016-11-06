/* 2016.09.20 22:15
 * P_116
 * dispay multiple dimension array using auto
 */
#include <iostream>

using MulDimArray4 = int[4];

int main(int argc, char **argv)
{
	int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};

	for (auto &i : ia)
		for (auto const &j : i)
			std::cout << j << ' ';
	std::cout << std::endl;

	for (auto i = 0; i < std::end(ia)-std::begin(ia); ++ i)
		for (auto j = 0; j < std::end(ia[i])-std::begin(ia[i]); ++j)
			std::cout << ia[i][j] << ' ';
	std::cout << std::endl;

	for (auto i = std::begin(ia); i < std::end(ia); ++ i)
		for (auto j = std::begin(*i); j < std::end(*i); ++ j)
			std::cout << *j << ' ';
	std::cout << std::endl;

	return 0;
}
