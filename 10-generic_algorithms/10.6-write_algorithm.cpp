/* 2016.12.13 20:53
 * P_342
 * !!!
 * back_inserter: !!!
 *	head file <iterator>
 * replace(itBeg, itEnd, target, replacement): !!!
 *	replace 'target' with 'replacement'
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

void WritingAlgorithm()
{
	vector<int> vecInt({1, 2, 3, 4, 5, 6});
	// all set 0
	fill(vecInt.begin(), vecInt.end(), 0);
	// all set 1
	fill_n(vecInt.begin(), vecInt.size(), 1);

	auto it = back_inserter(vecInt);
	*it = 2;
	fill_n(it, 3, 3);
	for (auto const intNum : vecInt)
		cout << intNum << ' ';
	cout << endl;
	// output: 1 1 1 1 1 1 2 3 3 3 

	int arrA[] = {0, 1, 2, 3, 4};
	int arrB[sizeof(arrA)/sizeof(arrA[0])];
	auto ret = copy(begin(arrA), end(arrA), arrB);
	for (auto const intNum : arrB)
		cout << intNum << ' ';
	// output: 0 1 2 3 4 
	cout << endl << ret << ' ' << end(arrB) << endl;
	// output: 0x7ffe18230ab4 0x7ffe18230ab4

	replace(vecInt.begin(), vecInt.end(), 1, 0);
	for (auto const intNum : vecInt)
		cout << intNum << ' ';
	cout << endl;
	// output: 0 0 0 0 0 0 2 3 3 3 

	list<int> lstInt;
	replace_copy(vecInt.begin(), vecInt.end(), back_inserter(lstInt), 0, 4);
	for (auto const intNum : lstInt)
		cout << intNum << ' ';
	cout << endl;
	// output: 4 4 4 4 4 4 2 3 3 3 
}
void SetLstInt0(list<int> &lstInt)
{
	fill_n(lstInt.begin(), lstInt.size(), 0);
}
int main(int argc, char **argv)
{
	// WritingAlgorithm();
	list<int> lstInt({0, 1, 2, 3, 4, 5, 6});
	SetLstInt0(lstInt);
	for (auto intNum : lstInt)
		cout << intNum << ' ';
	// output: 0 0 0 0 0 0 0 

	return 0;
}

