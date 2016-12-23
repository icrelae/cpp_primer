/* 2016.12.23 21:16
 * P_365
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> vecInt({0, 1, 2, 3, 0, 5, 6});
	cout << find(vecInt.crbegin(), vecInt.crend(), 0).base() - vecInt.cbegin();
	// output: 5

	return 0;
}

