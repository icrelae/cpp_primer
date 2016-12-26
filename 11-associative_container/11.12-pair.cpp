/* 2016.12.25 11:06
 * P_381
 * !!!
 * pair: !!!
 * head file: <utility>
 * pair<T1, T2> p;
 * pair<T1, T2> p(valFirst, valSecond);
 * pair<T1, T2> p={valFirst, valSecond};
 * make_pair(valFirst, valSecond): return pair(valFirst, valSecond)
 * p.first, p.second
 * p1 <|>|<=|>=|==|!= p2
 */
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char **argv)
{
	pair<string, int> pirStrInt;
	vector<pair<string, int>> vecPirStrInt;
	while (cin >> pirStrInt.first >> pirStrInt.second)
		vecPirStrInt.push_back(pirStrInt);
	for (auto const &pir : vecPirStrInt)
		cout << pir.first << ' ' << pir.second << endl;

	return 0;
}

