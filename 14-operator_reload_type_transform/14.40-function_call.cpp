/* 2017.02.13 21:00
 * P_509
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

class StrCompare {
	public:
		bool operator()(const string &strA, const string &strB)
		{
			return strA.size() < strB.size();
		}
};

void Biggies(vector<string> &words, vector<string>::size_type sz)
{
	stable_sort(words.begin(), words.end(), StrCompare());
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

