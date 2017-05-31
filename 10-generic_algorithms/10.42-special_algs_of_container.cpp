/* 2016.12.24 11:28
 * P_370
 * !!!
 * special algorithm of container: !!!
 * common sort() need random-access iterator, so its unsuitable for list|forward_list
 * as a result, list|forward_list have some algorithms as thire member function, 
 * which mast be used rather than common algorithms
 *
 * lst.merge(lst2):
 *	merge lst2 into lst, both lst and lst2 have to be ordered
 *	lst2 become empty after merge
 * lst.merge(lst2, comp): using 'comp' instead of default '<'
 * lst.remove(val): remove elements equal to 'val'
 * lst.remove_if(pred)
 * lst.reverse()
 * lst.sort()
 * lst.sort(comp): using 'comp' instead of default '<'
 * lst.unique(): erase continuous elements with same value
 * lst.unique(pred)
 *
 * splice: exclusive to list|forward_list !!!
 * lst.splice(args)
 * flst.splice_after(args)
 *	(itPos, lst2)
 * 	(itPos, lst2, itPos2)
 * 	(itPos, lst2, itBeg, itEnd)
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iterator>

using namespace std;

void ExclusiveAlgorithmEG()
{
	vector<int> vecInt({1, 2, 2, 3, 3, 4, 5, 1});
	unique(vecInt.begin(), vecInt.end());
	for (auto const &x : vecInt)
		cout << x << ' ';
	cout << endl;
	// output: 1 2 3 4 5 4 5 1
	list<int> lstInt({1, 2, 2, 3, 3, 4, 5, 1});
	lstInt.unique();
	for (auto const &x : lstInt)
		cout << x << ' ';
	// output: 1 2 3 4 5 1
}
void SpliceEG()		// splice()|splice_after() !!!
{
	list<int> lstInt1({1, 2, 3});
	list<int> lstInt2({4, 5, 6, 7, 8, 9});
	forward_list<int> flstInt1({1, 2, 3});
	forward_list<int> flstInt2({4, 5, 6, 7, 8, 9});

	lstInt1.splice(lstInt1.begin(), lstInt2, lstInt2.begin());
	flstInt1.splice_after(flstInt1.begin(), flstInt2, flstInt2.begin());
	for (auto const &x : lstInt1)
		cout << x << ' ';
	cout << endl;
	// output: 4 1 2 3 
	for (auto const &x : flstInt1)
		cout << x << ' ';
	cout << endl;
	// output: 1 5 2 3 

	lstInt1.splice(lstInt1.begin(), lstInt2, lstInt2.begin(), ++++lstInt2.begin());
	flstInt1.splice_after(flstInt1.begin(), flstInt2, flstInt2.begin(), ++++flstInt2.begin());
	for (auto const &x : lstInt1)
		cout << x << ' ';
	cout << endl;
	// output: 5 6 4 1 2 3 
	for (auto const &x : flstInt1)
		cout << x << ' ';
	cout << endl;
	// output: 1 6 5 2 3 

	lstInt1.splice(lstInt1.begin(), lstInt2);
	flstInt1.splice_after(flstInt1.begin(), flstInt2);
	for (auto const &x : lstInt1)
		cout << x << ' ';
	cout << endl;
	// output: 7 8 9 5 6 4 1 2 3 
	for (auto const &x : flstInt1)
		cout << x << ' ';
	cout << endl;
	// output: 1 4 7 8 9 6 5 2 3 
}

void ElimDuplicate(list<string> &words)
{
	words.sort();
	words.unique();
}
int main(int argc, char **argv)
{
	ExclusiveAlgorithmEG();
	SpliceEG();
	list<string> words({"a", "a", "b", "c", "c", "a"});
	ElimDuplicate(words);
	for (auto const &word : words)
		cout << word << ' ';
	// output: a b c 

	return 0;
}

