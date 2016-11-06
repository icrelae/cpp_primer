/* 2016.09.24 21:01
 * P_133
 */
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	std::vector<int> vec = {4, 3, 2, 1, 0, -1};
	auto p = vec.begin();
	while (p != vec.end() && *p >= 0 && *p < 10)
		std::cout << ++*p << std::endl;	// 5 6 7 8 9 ....

	while (p != vec.end() && *p >= 0)
		std::cout << *++p << std::endl;	// 3 2 1 0 -1



	return 0;
}

