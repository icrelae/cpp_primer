/* 2016.11.14 22:49
 * P_297
 * !!!
 * operator unavailable for list, forward_list: !!!
 * iter + n, iter - n
 * iter += n, iter -= n
 * iter1 - iter2
 * >, >=, <, <=
 * operator unavailable for forward_list: !!!
 * --iter
 * operator available for all(vector, deque, list, forward_list, array, string) !!!
 * *iter, iter->member, ++iter, iter1 == iter2, iter1 != iter2
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char **argv)
{
	list<int> lst1;
	list<int>::iterator iter1 = lst1.begin();
	list<int>::iterator iter2 = lst1.end();
	
	// while (iter1 < iter2) {
	while (iter1 != iter2) {
		++iter1;
	}

	return 0;
}
