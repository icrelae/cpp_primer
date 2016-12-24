/* 2016.12.24 21:00
 * P_378
 * set: value are unique, even assign a 'set' with 'multiset'
 * list: repeatable
 */
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char **argv)
{
	multiset<int> mset({1, 1, 2, 3, 1, 1, 2});
	set<int> set(mset.begin(), mset.end());
	for (auto const &x : mset)
		cout << x << ' ';
	cout << endl;
	// output: 1 1 1 1 2 2 3 
	for (auto const &x : set)
		cout << x << ' ';
	cout << endl;
	// output: 1 2 3 

	return 0;
}

