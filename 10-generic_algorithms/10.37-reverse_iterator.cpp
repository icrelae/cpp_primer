/* 2016.12.23 21:16
 * P_365
 */
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> vecInt({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
	vector<int> vecIntReverse1(vecInt.crbegin()+3, vecInt.crend()-2), vecIntReverse2;
	for (auto const &x : vecIntReverse1)
		cout << x << ' ';

	return 0;
}

