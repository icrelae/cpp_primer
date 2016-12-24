/* 2016.12.24 14:10
 * P_376
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string, size_t> CountWords(vector<string> const vecStr)
{
	map<string, size_t> mapWords;
	for (auto const &str : vecStr) {
		++mapWords[str];
	}
	return mapWords;
}

int main(int argc, char **argv)
{
	vector<string> vecStr({"a", "b", "a"});
	map<string, size_t> mapWords = CountWords(vecStr);
	for (auto const word : mapWords)
		cout << word.first << ' ' << word.second << ' ';
	// output: a 2 b 1

	return 0;
}

