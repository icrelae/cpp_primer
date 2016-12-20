/* 2016.12.11 22:59
 * P_339
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, char **argv)
{
	vector<double> vecDbl({1, 2, 3, 4});
	cout << accumulate(vecDbl.cbegin(), vecDbl.cend(), 0);

	return 0;
}

