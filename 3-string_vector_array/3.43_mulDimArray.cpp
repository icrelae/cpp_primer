/* 2016.09.20 22:15
 * P_116
 * dispay multiple dimension array
 * !!! 
 */
#include <iostream>

int main(int argc, char **argv)
{
	int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};

	// !!!
	for (int (&i)[4] : ia)
		for (int const &j : i)
			std::cout << j << ' ';
	std::cout << std::endl;

	for (int i = 0; i < std::end(ia)-std::begin(ia); ++ i)
		for (int j = 0; j < std::end(ia[i])-std::begin(ia[i]); ++j)
			std::cout << ia[i][j] << ' ';
	std::cout << std::endl;

	for (int (*i)[4] = ia; i < std::end(ia); ++ i)
		for (int *j = *i; j < std::end(*i); ++ j)
			std::cout << *j << ' ';
	std::cout << std::endl;

	return 0;
}
