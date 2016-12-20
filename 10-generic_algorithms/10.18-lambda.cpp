/* 2016.12.15 21:39
 * P_349
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void ElimDuplicatedStr(vector<string> &vecStr)
{
	sort(vecStr.begin(), vecStr.end());
	auto endOfUnique = unique(vecStr.begin(), vecStr.end());
	vecStr.erase(endOfUnique, vecStr.end());
}

void Biggies(vector<string> &words, vector<string>::size_type sz)
{
	stable_sort(words.begin(), words.end(),
			[] (string const &strA, string const &strB) -> bool {
				return strA.size() < strB.size();
			});
	auto itWords = partition(words.begin(), words.end(),
			[sz] (string const &str) -> bool {
				return str.size() > sz;
			});
	for_each(words.begin(), itWords,
			[] (string const &str) {
				cout << str << ' ';
			});
}

int main(int argc, char **argv)
{
	vector<string> vecStr({
			"123456",
			"223456",
			"23",
			"3456",
			"456",
			"567890",
			"6"});
	Biggies(vecStr, 3);
	// output: 567890 123456 223456 3456 

	return 0;
}

