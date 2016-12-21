/* 2016.12.21 22:08
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool CheckStrSize(string const &str, string::size_type const size)
{
	return str.size() > size;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	auto itUnique = unique(words.begin(), words.end());
	words.erase(itUnique, words.end());
	stable_sort(words.begin(), words.end(),
			[] (string const &a, string const &b) {
				return a.size() < b.size();
			});
	auto itWords = find_if(words.begin(), words.end(),
			bind(CheckStrSize, _1, sz));
	while (itWords != words.end())
		cout << *itWords++ << ' ';
}

int main(int argc, char **argv)
{
	vector<string> vecStr({
			"12345",
			"123",
			"1234567",
			"1234",
			"123456",
			});
	biggies(vecStr, 4);
	// output: 12345 123456 1234567 

	return 0;
}

