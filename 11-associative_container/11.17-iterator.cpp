/* 2016.12.25 11:40
 * P_383
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	multiset<int> c({1, 2, 3});
	vector<int> v({3, 4, 5});

	copy(v.begin(), v.end(), inserter(c, c.end()));
	// output: 1 2 3 3 4 5 ; 3 4 5 

	// invalid, iterators of set are constant
	//copy(v.begin(), v.end(), back_inserter(c));

	copy(c.begin(), c.end(), inserter(v, v.end()));
	// output: 1 2 3 ; 3 4 5 1 2 3 

	copy(c.begin(), c.end(), back_inserter(v));
	// output: 1 2 3 ; 3 4 5 1 2 3 

	for (auto const &x : c)
		cout << x << ' ';
	cout << "; ";
	for (auto const &x : v)
		cout << x << ' ';

	return 0;
}

