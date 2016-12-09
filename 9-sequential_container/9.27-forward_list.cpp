/* 2016.11.20 16:13
 * P_314
 * !!!
 * add and delete for forward_list: !!!
 * c.before_begin(): return an iterator point to previous node of first element
 * c.cbefore_bdgin(): return an const_iterator
 * c.insert_after(itPos, t): insert t after itPos
 * c.insert_after(itPos, n, t): insert t after itPos n times
 * c.insert_after(itPos, itPosBeg, itPosEnd): insert from itPosBeg to itPosEnd after itPos
 * c.insert_after(itPos, {0, 1, 2}): insert {} after itPos
 * c.emplace_after(itPos, args): initialize an element after itPos using args; return iterator point to new element
 * c.erase_after(itPos): delete element after itPos, return next element of itPos
 * c.erase_after(itPosBeg, itPosEnd): delete elements in ranger from itPosBeg to itPosEnd
 */
#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

void DeleteOdd(forward_list<int> &flst)
{
	auto curr = flst.cbegin();
	auto prior = flst.cbefore_begin();
	while (curr != flst.cend()) {
		// watch out invalid iterator after erase !!!
		if ((*curr%2) == 1) {
			curr = flst.erase_after(prior);
		} else {
			++curr;
			++prior;
		}
	}
}
int main(int argc, char **argv)
{
	forward_list<int> flst{0, 1, 2, 3, 4, 5, 6};
	DeleteOdd(flst);
	for (auto x : flst)
		cout << x << ' ';

	return 0;
}
