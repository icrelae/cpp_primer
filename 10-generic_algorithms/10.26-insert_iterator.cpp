/* 2016.12.22 19:39
 * P_359
 * !!!
 * insert iterator: !!!
 * back_inserter(container<type>): return iterator using push_back() to insert at tail
 * front_inserter(container<type>): return iterator using front_back() to insert at head
 * inserter(container<type>, container<type>::iterator): return iterator using
 *	insert() to insert at argument 'it'
 *
 * it = t:	insert 't' at it
 * *it, ++it, it++: do nothing but return it
 */
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

void InsertIteratorEG()
{
	list<int> lstInt1({1, 2, 3, 4});
	list<int> lstInt2, lstInt3;
	// front_instert() need container have push_front(), so it cannot be
	// using on vector<> !!!
	copy(lstInt1.cbegin(), lstInt1.cend(), front_inserter(lstInt2));
	copy(lstInt1.cbegin(), lstInt1.cend(), inserter(lstInt3, lstInt3.begin()));
	for (auto const num : lstInt2)
		cout << num << ' ';
	for (auto const num : lstInt3)
		cout << num << ' ';
	// output: 4 3 2 1 1 2 3 4 
}

int main(int argc, char **argv)
{
	InsertIteratorEG();

	return 0;
}

