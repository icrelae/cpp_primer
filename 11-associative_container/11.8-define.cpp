/* 2016.12.24 21:00
 * P_378
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> vecInt({1, 1, 2, 3, 2, 1, 3, 2, 1, 2, 1, 3});
	vector<int> vecIntElimDuplct;
	for (auto const &x : vecInt) {
		if (find(vecIntElimDuplct.begin(), vecIntElimDuplct.end(), x) == vecIntElimDuplct.end())
			vecIntElimDuplct.push_back(x);
	}
	for (auto const &x : vecIntElimDuplct)
		cout << x << ' ';
	// output: 1 2 3 

	return 0;
}

