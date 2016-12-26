/* 2016.12.26 11:47
 * P_386
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	map<string, size_t> word_count;
	string word;

	while (cin >> word)
		++(word_count.insert({word, 0}).first->second);

	return 0;
}

