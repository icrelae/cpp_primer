/* 2016.12.13 22:10
 * P_344
 * !!!
 * sort algorithms: !!!
 * using '<' of elements type to sort
 * sort(itBeg, itEnd)
 * unique(itBeg, itEnd): return iterator after last non-dupicated element
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void ElimDuplicates(vector<int> &vecInt)
{
	sort(vecInt.begin(), vecInt.end());
	auto end_unique = unique(vecInt.begin(), vecInt.end());
	vecInt.erase(end_unique, vecInt.end());
}
int main(int argc, char **argv)
{
	vector<int> vecInt({1, 2, 2, 3, 3, 3, 4, 4, 4, 4});
	ElimDuplicates(vecInt);
	for (auto const intNum : vecInt)
		cout << intNum << ' ';
	// output: 1 2 3 4 

	return 0;
}

