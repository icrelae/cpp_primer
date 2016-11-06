/* 2016.09.17 21:37
 * P_108
 */
#include <iostream>
#include <vector>

int Compare(const int *array1, const int *array2, const size_t size)
{
	if (size == 0)
		return 0;
	size_t index = 0;
	while (index < size && *array1 == *array2) {
		++ array1;
		++ array2;
		++ index;
	}

	return index < size ? *array1 - *array2 : 0;
}

int Compare(const std::vector<int> &array1,
		const std::vector<int> &array2,
		const size_t size)
{
	if (size == 0)
		return 0;
	std::vector<int>::size_type index = 0;
	while (index < size && array1[index] == array2[index])
		++ index;

	return index < size ? array1[index] - array2[index] : 0;
}

#define _ARRAY0 {0, 1, 2}
#define _ARRAY1 {4, 5, 6}

int main(int argc, char **argv)
{
	int ar1[] = _ARRAY0;
	int ar2[] = _ARRAY1;
	std::vector<int> vec1 = _ARRAY0;
	std::vector<int> vec2 = _ARRAY1;
	std::cout << Compare(ar1, ar1, sizeof(ar1)/sizeof(ar1[0])) << std::endl;
	std::cout << Compare(ar1, ar2, sizeof(ar1)/sizeof(ar1[0])) << std::endl;
	std::cout << Compare(ar2, ar1, sizeof(ar1)/sizeof(ar1[0])) << std::endl;
	std::cout << Compare(vec1, vec1, vec1.size()) << std::endl;
	std::cout << Compare(vec1, vec2, vec1.size()) << std::endl;
	std::cout << Compare(vec2, vec1, vec1.size()) << std::endl;

	return 0;
}

