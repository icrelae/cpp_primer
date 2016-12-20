/* 2016.12.09 20:00
 * P_337
 * !!!
 * header file of generic algorithms: <algorithm> !!!
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void SummaryEG()
{
	vector<int> vecInt({1, 2, 3, 4, 5});
	vector<int>::iterator resultVecInt = find(vecInt.begin(), vecInt.end(), 3);
	resultVecInt == vecInt.end() ?
		cout << "is not present" << endl :
		cout << "is present" << endl;
	
	string str("a string");
	auto resultStr = find(str.begin()+1, str.end(), 'r');

	int arrInt[] = {1, 2, 3, 4, 5, 6};
	auto resultArrInt = find(begin(arrInt), end(arrInt), 3);
	resultArrInt = find(arrInt+1, arrInt+4, 3);
}
int main(int argc, char **argv)
{
	vector<int> vecInt({1, 2, 2, 3, 3, 3, 4, 4, 4, 4});

	cout << count(vecInt.begin(), vecInt.end(), 3) << endl;
	cout << count(vecInt.begin()+1, vecInt.end(), 1) << endl;

	return 0;
}

