/* 2016.11.19 16:12
 * P_309
 * forward_list don't have push_back and emplace_back
 * vector and string don't have push_front and emplace_front
 * emplace(args): call constructor using args, other using copy
 * push_back(t), emplace_back(constructor_args), return void
 * push_front(t), emplace_front(constructor_args), return void
 * insert(itPos, t), emplace(itPos, constructor_args): insert t before itPos which is a iterator, return iterator point to new element
 * insert(itPos, n, t): insert n times t before itPos, return iterator point to first new element, if n=0, return itPos
 * insert(itPos, itBeg, itEnd): insert from itBeg to itEnd befor itPos, return iterator point to first new element, if range is empty, return itPos
 * insert(itPos, {1, 2, 3, 4}): insert {} before itPos, return iterator point to first new element, if {} is empty, return itPos
 * insert to a vector, string , or deque will lead to invalidation of all poingtor, reference and iterator point of that seq-container !!!
 */
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

using namespace std;

int main(int argc, char **argv)
{
	deque<string> deqStr;
	string word;
	while (cin >> word)
		deqStr.push_front(word);
	for (const auto itDeqStr : deqStr)
		cout << itDeqStr << ' ';


	return 0;
}

