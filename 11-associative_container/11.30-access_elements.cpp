/* 2016.12.27 13:07
 * P_391
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char **argv)
{
	multimap<string, int> m({
				{"a", 1},
				{"a", 2},
				{"c", 3},
				{"e", 5}
			});
	pair<decltype(m)::const_iterator, decltype(m)::const_iterator> p;
	p = m.equal_range("a");
	decltype(m)::const_iterator itBeg = p.first, itEnd = p.second;
	cout << itBeg->first << itBeg->second << ' ';
	cout << itEnd->first << itEnd->second << ' ';
	// output: a1 c3 

	return 0;
}

