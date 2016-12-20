/* 2016.12.09 20:26
 * P_339
 * !!!
 * read-only algorithms: !!!
 * find(beg, end, val)
 * count(beg, end, val)
 * accumulate(beg, end, val):
 *	get sum from beg to end, val is initialized value of sum
 *	elements should be addable
 *	type of val determine which types operator will be used
 * equal(a.beg, a.end, b.beg): whether a equals b
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void ReadOnlyAlgorithmsEG()
{
	vector<string> vecStr({"a", "b", "c", "d"});
	string sum = accumulate(vecStr.cbegin(), vecStr.cend(), string("sum: "));
	/* error due to 'char *' have no operator '+' */
	//string sum = accumulate(vecStr.begin(), vecStr.end(), "sum: ");
	cout << sum << endl;

	vector<int> vecInt({1, 2, 3, 4, 5});
	vector<double> vecDbl1({1, 2, 3, 4, 5, 6});
	vector<double> vecDbl2({1, 2, 2, 4, 5, 6});
	/* types of elements dont have to be same*/
	cout << equal(vecInt.cbegin(), vecInt.cend(), vecDbl1.begin());
	cout << equal(vecInt.cbegin(), vecInt.cend(), vecDbl2.begin());
	/* output:
	 * sum: abcd
	 * 10
	 */
}

double AccumulateVecInt(vector<double>::const_iterator itVecIntBeg, 
		vector<double>::const_iterator itVecIntEnd)
{
	return accumulate(itVecIntBeg, itVecIntEnd, 0);
}

int main(int argc, char **argv)
{
	vector<double> vecDbl({1, 2, 3, 4, 5});
	ReadOnlyAlgorithmsEG();
	cout << AccumulateVecInt(vecDbl.begin(), vecDbl.end());

	return 0;
}

