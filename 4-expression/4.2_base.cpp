/* 2016.09.24 16:17
 * P_123
 * priority of calculate
 */
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	std::vector<int> vec(1, 3);

	std::cout << *vec.begin() << " = ";
	std::cout << *(vec.begin()) << std::endl;

	std::cout << *vec.begin() + 1 << " = ";
	std::cout << (*(vec.begin())) + 1 << std::endl;

	return 0;
}

