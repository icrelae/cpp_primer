/* 2016.11.23 21:27
 * P_315
 * resize: !!!
 * array don't have reseze()
 * c.resize(n)
 * c.resize(n, t): initialize new elements using t
 * if n less than current size, iterator/pointer/reference maybe become invalid
 * c.resize(n): need element have default constructor
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8};
	vec.resize(4);
	for (auto const x : vec)
		cout << x << ' ';
	// output: 0, 1, 2, 3

	return 0;
}

