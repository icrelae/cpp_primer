/* 2016.09.04 14:54
 * P_104
 */
#include <iostream>

int main(int argc, char **argv)
{
	constexpr size_t arraySize = 10;
	int a[arraySize];

	for (size_t index = 0; index < arraySize; ++ index)
		a[index] = index;
	for (auto i : a)
		std::cout << i << ' ';

	return 0;
}

