/* 2016.12.26 11:47
 * P_386
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char **argv)
{
	map<string, multimap<string, string>> families({
			{"lastName1", {
				{"a", "lastName1"},
				{"b", "lastName1"},
				{"c", "lastName1"}}}
			});
	families.insert({"lastName2", {
			{"d", "lastName2"},
			{"e", "lastName2"},
			{"f", "lastName2"}}});
	families["lastName3"] = {
		{"g", "lastName3"},
		{"h", "lastName3"},
		{"i", "lastName3"}};
	for (auto const &family : families) {
		cout << family.first << ':';
		for (auto const &name : family.second)
			cout << name.first << ' ';
		cout << endl;
	}
	/* output:
	 *	lastName1:a b c 
	 *	lastName2:d e f 
	 *	lastName3:g h i 
	 */

	return 0;
}

