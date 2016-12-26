/* 2016.12.25 11:06
 * P_381
 */
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char **argv)
{
	vector<pair<string, int>> vecPirStrInt;
	string str;
	int val;
	while (cin >> str >> val) {
		pair<string, int> pirStrInt1({str, val});
		pair<string, int> pirStrInt2 = {str, val};
		pair<string, int> pirStrInt3 = make_pair(str, val);
		vecPirStrInt.push_back(pirStrInt1);
	}
	for (auto const &pir : vecPirStrInt)
		cout << pir.first << ' ' << pir.second << endl;

	return 0;
}

