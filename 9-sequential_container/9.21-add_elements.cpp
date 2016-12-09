/* 2016.11.19 16:12
 * P_309
 * !!!
 * ???
 * for deque, insert at head and tail costing constant time, at other site will be very time-consuming !!!
 * insert/eplace enlements into vector/string/deque will cause invalidation of iterators/references/pointers point to it !!!
 *
 * allocate new memory for every insert ???
 */
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

using namespace std;

int main(int argc, char **argv)
{
	vector<string> lst;
	string word;
	auto iter = lst.begin();
	while (cin >> word)
		iter = lst.insert(iter, word);
	for (const auto itList : lst)
		cout << itList << ' ';

	return 0;
}

