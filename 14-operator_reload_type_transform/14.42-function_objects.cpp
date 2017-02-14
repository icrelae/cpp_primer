/* 2017.02.14 20:58
 * P_510
 * plus<Type>
 * minus<Type>
 * multiplies<Type>
 * divedes<Type>
 * modulus<Type>
 * negate<Type>
 * equal_to<Type>
 * not_equal_to<Type>
 * greater<Type>
 * grether_equal<Type>
 * less<Type>
 * less_equal<Type>
 * logical_and<Type>
 * logical_or<Type>
 * logical_not<Type>
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

void FunctionObjsEG()
{
	plus<int> intAdd;
	negate<int> intNegate;
	int sum = intAdd(10, 20);	// sum == 30
	sum = intNegate(sum);		// sum == -30
}
int main(int argc, char **argv)
{
	vector<int> vecInt{1, 11, 111, 1111, 11111};
	size_t counter = count_if(vecInt.begin(), vecInt.end(), 
			bind(greater<int>(), _1, 1024));
	cout << counter << endl;

	vector<string> vecStr{"pooh", "pooh", "asd"};
	vector<string>::const_iterator it = find_if(vecStr.begin(), vecStr.end(),
			bind(equal_to<string>(), _1, "pooh"));
	cout << *it << endl;

	transform(vecInt.begin(), vecInt.end(), vecInt.begin(),
			bind(multiplies<int>(), _1, 2));
	for (int x : vecInt)
		cout << x << ' ';
	/* output:
	 *	2
	 *	pooh
	 *	2 22 222 2222 22222 
	 */


	return 0;
}

