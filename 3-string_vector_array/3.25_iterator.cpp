/* 2016.08.30 23:13
 * P_101
 */
#include <iostream>
#include <vector>

using std::vector;

int main(int argc, char **argv)
{
	const int scores[] = {42, 65, 95, 100, 39, 67, 95,
		76, 88, 76, 83, 92, 76, 93};
	vector<int> vec(11, 0);
	auto it = vec.begin();

	for (int i = 0; i < 14; ++ i)
		*(it + scores[i]/10) += 1;
	for (it = vec.begin(); it != vec.end(); ++ it)
		std::cout << *it << ' ';

	return 0;
}

/* input:
 * 42 65 95 100 39 67 95 76 88 76 83 92 76 93
 * output:
 * 0 0 0 1 1 0 2 3 2 4 1
 */
