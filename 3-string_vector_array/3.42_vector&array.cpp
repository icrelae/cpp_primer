/* 2016.09.18 23:40
 * P_112
 * copy vector to array
 */
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	int array[10] = {-1};
	std::vector<int> vec = {0, 1, 2, 3, 4, 5};
	
	for (std::vector<int>::size_type i = 0; i < vec.size(); ++ i) {
		array[i] = vec[i];
	}
	for (int *p = array; p != std::end(array); ++ p)
		std::cout << *p << ' ';

	return 0;
}

