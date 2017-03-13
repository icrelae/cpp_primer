/* 2017.03.13 21:36
 * P_583
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template<typename IteratorT, typename ValueT>
IteratorT my_find(const IteratorT &itBeg, const IteratorT &itEnd, const ValueT &val)
{
	auto it = itBeg;	// here lost 'const' !!!
	while (it != itEnd && *it != val)
		++it;
	return it;
}

int main(int argc, char **argv)
{
	vector<int> vecInt{0, 1, 2, 3, 4, 5};
	list<string> lstStr{"a", "b", "c", "d"};
	vector<int>::iterator itVecInt;
	itVecInt = my_find(vecInt.begin(), vecInt.end(), 3);
	if (itVecInt == vecInt.end())
		cout << "end" << endl;
	else
		cout << *itVecInt << endl;
	itVecInt = my_find(vecInt.begin(), vecInt.end(), 8);
	if (itVecInt == vecInt.end())
		cout << "end" << endl;
	else
		cout << *itVecInt << endl;

	list<string>::iterator itLstStr;
	itLstStr = my_find(lstStr.begin(), lstStr.end(), "b");
	if (itLstStr == lstStr.end())
		cout << "end" << endl;
	else
		cout << *itLstStr << endl;
	itLstStr = my_find(lstStr.begin(), lstStr.end(), "g");
	if (itLstStr == lstStr.end())
		cout << "end" << endl;
	else
		cout << *itLstStr << endl;
	/* output:
	 *	3 end
	 *	b end
	 */


	return 0;
}

