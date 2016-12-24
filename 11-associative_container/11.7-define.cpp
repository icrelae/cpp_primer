/* 2016.12.24 21:00
 * P_378
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char **argv)
{
	map<string, vector<string>> families({
				{"lastName1", {"a", "b", "c"}},
				{"lastName2", {"d", "e", "f"}}
			});
	families["lastName3"] = {"g", "h", "i"};
	for (auto const &family : families) {
		cout << family.first << ':';
		for (auto const &name : family.second)
			cout << name << ' ';
		cout << endl;
	}
	/* output:
	 *	lastName1:a b c 
	 *	lastName2:d e f 
	 *	lastName3:g h i 
	 */

	return 0;
}

