/* 2016.12.26 11:47
 * P_386
 * pair<map<string, vector<int>>::const_iterator, bool>
 * pair<string, vector<int>>
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	map<string, vector<int>> m;
	vector<int> vecInt({1, 2, 3});

	pair<decltype(m)::const_iterator, bool> p = m.insert({"a", vecInt});
	cout << p.second << ' ' << p.first->first << ' ';
	for (auto const &intNum : p.first->second)
		cout << intNum << ' ';
	// output: 1 a 1 2 3 
	pair<decltype(m)::const_iterator, bool> p1 = m.insert({"a", vecInt});
	cout << p1.second << ' ' << p1.first->first << ' ';
	for (auto const &intNum : p1.first->second)
		cout << intNum << ' ';
	// output: 0 a 1 2 3 

	return 0;
}

