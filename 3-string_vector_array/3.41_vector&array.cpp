/* 2016.09.18 23:32
 * P_112
 * initialize vector using array
 */
#include <iostream>
#include <vector>

void DisplayVector(std::vector<int> vec)
{
	for (auto const it : vec)
		std::cout << it << ' ';
	std::cout << std::endl;
}
int main(int argc, char **argv)
{
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7};
	std::vector<int> vec1(std::begin(array), std::end(array));
	std::vector<int> vec2(array+1, array+4);

	DisplayVector(vec1);	// 0 1 2 3 4 5 6 7
	DisplayVector(vec2);	// 1 2 3

	return 0;
}

