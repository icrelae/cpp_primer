/* 2016.11.23 21:45
 * P_317
 * !!!
 * add/delete elements maybe influence iterator/pointer/reference: !!!
 * 1) add into vector/string: if reallocate space, all iterator/pointer/reference become invald; otherwise, iterator/pointers/reference before inserted element are valid, others are invalid
 * 2) delete from vector/string: iterator/pointer/reference before deleted are valid, others are invalid
 * 3) add into deque: inserting into head/tail make all iterator invalid, but won't influencing pointer and reference; inserting into other site make all iterator/pointer/reference invalid
 * 3) add into list/forward_list: all iterator/pointer/reference valid
 * 4) delete from list/forward_list: all iterator/pointer/reference valid but pointed to deleted element
 * don't keep iterator getting by end() !!!
 */
#include <iostream>
#include <forward_list>
#include <list>

using namespace std;

void DelEvenList(list<int> &lst)
{
	auto iter = lst.cbegin();
	while (iter != lst.end()) {
		if ((*iter % 2) == 1) {
			iter = lst.insert(iter, *iter);
			// list don't have +, -, >, < !!!
			++iter;
			++iter;
		} else {
			iter = lst.erase(iter);
		}
	}
}

void DelEvenForwardlist(forward_list<int> &fwdLst)
{
	auto iter = fwdLst.cbegin();
	auto iterPrior = fwdLst.cbefore_begin();
	while (iter != fwdLst.end()) {
		if ((*iter % 2) == 1) {
			iter = fwdLst.insert_after(iterPrior, *iter);
			// forward_list don't have +, -, >, <, -- !!!
			// iter still point to element after iterPrior !!!
			++iterPrior;
			++iterPrior;
			++iter;
			++iter;
		} else {
			iter = fwdLst.erase_after(iterPrior);
		}
	}
}

int main(int argc, char **argv)
{
	list<int> lst{0, 1, 2, 3, 4, 5, 6, 7};
	forward_list<int> fwdLst{0, 1, 2, 3, 4, 5, 6, 7};

	DelEvenList(lst);
	DelEvenForwardlist(fwdLst);
	for (auto const x : lst)
		cout << x << ' ';
	cout << endl;
	for (auto const x : fwdLst)
		cout << x << ' ';

	return 0;
}
