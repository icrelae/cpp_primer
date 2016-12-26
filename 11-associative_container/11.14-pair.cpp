/* 2016.12.24 21:00
 * P_381
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	map<string, vector<string>> families({
				{"lastName1", {"a", "b", "c"}},
				{"lastName2", {"d", "e", "f"}}
			});
	families["lastName3"] = {"g", "h", "i"};
	vector<pair<string, string>> births({
				{"a lastName1", "19800101"},
				{"b lastName1", "19800102"},
				{"c lastName1", "19800103"}
			});
	for (auto const &family : families) {
		cout << family.first << ':';
		for (auto const &name : family.second) {
			cout << name << ' ';
			auto const birth = find_if(births.begin(), births.end(),
					[name, family] (pair<string, string> p) {
						return name+' '+family.first == p.first;
					});
			if (birth != births.end())
				cout << birth->second << ' ';
		}
		cout << endl;
	}
	/* output:
	 *	lastName1:a 19800101 b 19800102 c 19800103 
	 *	lastName2:d e f 
	 *	lastName3:g h i 
	 */

	return 0;
}

