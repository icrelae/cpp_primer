/* 2016.12.24 14:10
 * P_376
 * !!!
 * ordered:
 *	map: key-value
 *	set: key
 *	multimap: allow duplicate
 *	multiset: allow duplicate
 * unordered: using hash-table to organize elements
 *	unordered_map
 *	unordered_set
 *	unordered_multimap
 *	unordered_multiset
 */
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

void MapNSetEG()
{
	map<string, size_t> word_count;
	set<string> exclude = {"as", "asd"};
	string word;
	while (cin >> word) {
		if (exclude.find(word) == exclude.end())
			++word_count[word];
	}
	for (auto const &w : word_count)
		cout << w.first << ' ' << w.second << ' ';
	// input:	a as asd as asdf as asd asdf
	// output:	a 1 asdf 2
}

int main(int argc, char **argv)
{
	MapNSetEG();

	return 0;
}

