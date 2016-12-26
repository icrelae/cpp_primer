/* 2016.12.26 18:45
 * P_391
 * !!!
 * find elements: !!!
 * c.find(key_type): return iterator of key or c.end()
 * c.count(key_type): return number of key, for non-duplicatable it's either 0 or 1
 * c.lower_bound(key_type):
 *	available on ordered associative container
 *	return first key which value -ge key
 * c.upper_bound(key_type):
 *	available on ordered associative container
 *	return first key which value -gt key
 * c.equal_range(key_type):
 *	return pair<decltype(c)::iterator itBeg, decltype(c)::iterator itEnd>
 *	ranger of elements which equal to the key, if not existent, all set c.end()
 *
 * lower_bound() and upper_bound() like begin() and end()
 *	if lower_bound() == upper_bound() means not found,
 *	then they'll return an iterator of applicable place to insert key
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <typeinfo>

using namespace std;

void FindEG()
{
	int key = 1;
	multimap<int, int> m({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
	auto numbersOfKey = m.count(key);
	auto itMap = m.find(key);
	while (numbersOfKey != 0) {
		cout << itMap->first << ' ' << itMap->second << ' ';
		--numbersOfKey;
	}
	cout << endl;

	for (auto itBeg = m.lower_bound(key), itEnd = m.upper_bound(key); 
			itBeg != itEnd; ++itBeg)
		cout << itMap->first << ' ' << itMap->second << ' ';
	cout << endl;
	
	pair<decltype(m)::const_iterator, decltype(m)::const_iterator> p;
	for (p = m.equal_range(key); p.first != p.second; ++p.first)
		cout << p.first->first << ' ' << p.first->second << ' ';

}

int main(int argc, char **argv)
{
	FindEG();

	return 0;
}

