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
	vector<int> vecInt({1, 2, 3, 4, 5, 6});
	vector<int>::const_iterator itVecInt= vecInt.end();
	while (itVecInt != vecInt.begin())
		cout << *(--itVecInt) << ' ';
	// output: 6 5 4 3 2 1 

	return 0;
}

