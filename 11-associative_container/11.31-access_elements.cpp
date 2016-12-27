/* 2016.12.27 13:07
 * P_391
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool Eliminate(multimap<string, string> &mmap, string const key)
{
	multimap<string, string>::size_type number = mmap.count(key);
	if (number != 0) {
		multimap<string, string>::const_iterator itErase = mmap.find(key);
		mmap.erase(itErase);
		return true;
	} else
		return false;
}

int main(int argc, char **argv)
{
	multimap<string, string> bookLib({
				{"author1", "a1b3"},
				{"author2", "a2b1"},
				{"author1", "a1b2"},
				{"author1", "a1b1"}
			});
	cout << Eliminate(bookLib, "author1") << ' ';
	for (auto const  &p : bookLib)
		cout << p.second << ' ';
	cout << Eliminate(bookLib, "author3") << ' ';
	for (auto const  &p : bookLib)
		cout << p.second << ' ';
	/* output:
	 * 1 a1b2 a1b1 a2b1
	 * 0 a1b2 a1b1 a2b1 
	 */
	return 0;
}

