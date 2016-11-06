/* 2016.08.29 22:42
 * P_99
 */
#include <iostream>
#include <vector>

using std::vector;

int main(int argc, char **argv)
{
	vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int>::iterator it = vec.begin();
	for ( ; it != vec.end(); ++ it)
		*it = *it * 2;
	for (it = vec.begin(); it != vec.end(); ++ it)
		std::cout << *it << ' ';

	return 0;
}

