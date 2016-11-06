/* 2016.09.04 14:54
 * P_104
 */
#include <iostream>
#include <cstring>
#include <vector>

void Task1()
{
	constexpr size_t arraySize = 10;
	int a[arraySize];
	int b[arraySize];

	for (size_t index = 0; index < arraySize; ++ index)
		a[index] = index;
	for (auto i : a) {
		std::cout << i << ' ';
	}

	memcpy(b, a, arraySize*sizeof(int));
	for (auto i : b) {
		std::cout << i << ' ';
	}
}

void Task2()
{
	std::vector<int> vec;

	for (size_t i = 0; i < 10; ++i)
		vec.push_back(i);
	std::vector<int> vec2 = vec;

	for (size_t i = 0; i < 10; ++i) {
		std::cout << vec[i] << ' ' << vec2[i] << std::endl;
	}
}

int main(int argc, char **argv)
{
	Task1();
	Task2();
	return 0;
}
