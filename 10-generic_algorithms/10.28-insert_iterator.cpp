/* 2016.12.22 19:39
 * P_359
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> vecInt({1, 2, 3, 4, 5, 6, 7, 8, 9});
	vector<int> arrVecInt[3];

	// 1, 2, 3, 4, 5, 6 ...
	copy(vecInt.begin(), vecInt.end(), inserter(arrVecInt[0], arrVecInt[0].begin()));
	// 1, 2, 3, 4, 5, 6 ...
	copy(vecInt.begin(), vecInt.end(), back_inserter(arrVecInt[1]));
	// invalid
	//copy(vecInt.begin(), vecInt.end(), fron_inserter(arrVecInt[2]));
	for (auto const vec : arrVecInt) {
		for (auto const num : vec)
			cout << num << ' ';
		cout << endl;
	}
	/* output:
	 * 1 2 3 4 5 6 7 8 9
	 * 1 2 3 4 5 6 7 8 9 
	 */


	return 0;
}

