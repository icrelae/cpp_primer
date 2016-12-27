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
	decltype(m)::const_iterator itLower, itUpper;
	itLower = m.lower_bound("a");
	itUpper = m.upper_bound("a");
	cout << itLower->first << itLower->second << ' ';
	cout << itUpper->first << itUpper->second << ' ';

	itLower = m.lower_bound("b");
	itUpper = m.upper_bound("b");
	cout << itLower->first << itLower->second << ' ';
	cout << itUpper->first << itUpper->second << ' ';

	itLower = m.lower_bound("g");
	itUpper = m.upper_bound("g");
	if (itLower == m.end())
		cout << "end" << ' ';
	if (itUpper == m.end())
		cout << "end" << ' ';
	cout << endl;
	// output: a1 c3 c3 c3 end end 
	
	pair<decltype(m)::const_iterator, decltype(m)::const_iterator> p;
	p = m.equal_range("a");
	cout << p.first->first << p.first->second << ' ';
	cout << p.second->first << p.second->second << ' ';
	p = m.equal_range("b");
	cout << p.first->first << p.first->second << ' ';
	cout << p.second->first << p.second->second << ' ';
	p = m.equal_range("g");
	if (p.first == m.end())
		cout << "end" << ' ';
	if (p.second == m.end())
		cout << "end" << ' ';
	// output: a1 c3 c3 c3 end end 

	return 0;
}

