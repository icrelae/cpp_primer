/* 2016.12.25 11:40
 * P_383
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <typeinfo>

using namespace std;

int main(int argc, char **argv)
{
	map<int, int> m({{1, 1}, {2, 2}});
	map<int, int>::iterator it = m.begin();
	it->second = 2;
	for (auto const &p : m)
		cout << p.first << ' ' << p.second << ' ';
	// output: 1 2 2 2 

	return 0;
}

