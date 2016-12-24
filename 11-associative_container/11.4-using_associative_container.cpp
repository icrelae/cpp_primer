/* 2016.12.24 14:10
 * P_376
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<string, size_t> CountWords(vector<string> vecStr)
{
	map<string, size_t> mapWords;
	set<char> punctuations({',', '.', ';'});
	for (auto &str : vecStr) {
		for (auto &ch : str) {
			ch = tolower(ch);
		}
		for (auto &punc : punctuations) {
			str.erase(find(str.begin(), str.end(), punc), str.end());
		}

		++mapWords[str];
	}
	return mapWords;
}

int main(int argc, char **argv)
{
	vector<string> vecStr({"a.", "b,", "A", "a"});
	map<string, size_t> mapWords = CountWords(vecStr);
	for (auto const word : mapWords)
		cout << word.first << ' ' << word.second << ' ';
	// output: a 3 b 1 

	return 0;
}

