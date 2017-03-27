/* 2016.12.26 11:47
 * P_386
 * !!!
 * insert: !!!
 *	c.insert(val)
 *	c.emplace(args)
 *		for non-multi: return 'pair<ContainerType::iterator it, bool bl>'
 *			'it' point to element equals to val
 *			'bl' indicate inserted or not
 *		for multi: feturn 'ContainerType::iterator'
 *		have to define 'operator==()' for content
 *	c.insert(itBeg, itEnd)
 *	c.insert({a, b, c, ...})
 *		return void
 *	c.insert(itPos, val)
 *	c.emplace(itPos, args)
 *		return 'ContainerType::iterator'
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void InsertEG()
{
	vector<int> vecInt({1, 2, 3, 1, 2});
	set<int> setInt; 
	map<int, int> mapInt; 

	setInt.insert(vecInt.cbegin(), vecInt.cend());
	pair<set<int>::const_iterator, bool> x = setInt.insert(1);
	cout << *x.first << ' ' << x.second << endl;	// output: 1 0
	x = setInt.insert(9);
	cout << *x.first << ' ' << x.second << endl;	// output: 9 1

	mapInt.insert({1, 1});
	mapInt.insert(make_pair(2, 2));
	mapInt.insert(pair<int, int>(3, 3));
	mapInt.insert(map<int, int>::value_type(4, 4));
}

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

		auto p = mapWords.insert({str, 0});
		//if (p.second == false)
			++p.first->second;
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

