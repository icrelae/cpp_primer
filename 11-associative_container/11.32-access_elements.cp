/* 2016.12.27 13:07
 * P_391
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <typeinfo>

using namespace std;

void ShowMultimap(multimap<string, string> const &mmap) {
	auto itBeg = mmap.begin();
	while (itBeg != mmap.end()) {
		string key = itBeg->first;
		cout << key << ": ";
		auto rangeOfKey = mmap.equal_range(key);
		multiset<string> books;		// set auto sort
		for (itBeg = rangeOfKey.first; itBeg != rangeOfKey.second; ++itBeg) {
			books.insert(itBeg->second);
		}
		for (auto const &bookName : books)
			cout << bookName << ' ';
		cout << endl;
	}
}

int main(int argc, char **argv)
{
	multimap<string, string> bookLib({
			{"author1", "a1b3"},
			{"author2", "a2b1"},
			{"author3", "a3b2"},
			{"author2", "a2b2"},
			{"author3", "a3b1"},
			{"author1", "a1b1"},
			{"author1", "a1b2"}
			});
	ShowMultimap(bookLib);
	/* output:
	 *	author1: a1b1 a1b2 a1b3 
	 *	author2: a2b1 a2b2 
	 *	author3: a3b1 a3b2 
	 */
	return 0;
}

