/* 2016.12.22 19:39
 * P_359
 * !!!
 * unique_copy(itBegOrigin, itEndOrigin, itBeginDestination): !!!
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> vecInt({1, 1, 2, 2, 3, 1, 1, 2, 2, 3, 3});
	vector<int> vecIntTarget;

	unique_copy(vecInt.begin(), vecInt.end(), back_inserter(vecIntTarget));
	for (auto const num : vecIntTarget)
		cout << num << ' ';
	// output: 1 2 3 1 2 3 

	return 0;
}

