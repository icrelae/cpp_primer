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
	map<string, vector<int>> m({{"a", vector<int>({1})}});
	decltype(m)::iterator it = m.find("a");
	cout << it->first << ' ' << it->second[0] << endl;
	// output: a 1

	return 0;
}

