/* 2017.03.13 22:08
 * P_583
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
// 'arr' have to be reference, otherise it will convert array into pointer !!!
void print(const T &arr)
{
	for (auto item = begin(arr); item != end(arr); ++item)
		cout << *item << ' ';
	cout << endl;
	for (auto item : arr)
		cout << item << ' ';
	cout << endl;
}

int main(int argc, char **argv)
{
	int arrInt[] = {1, 2, 3, 4};
	print(arrInt);
	char arrCha[] = {'a', 'b', 'c'};
	print(arrCha);
	/* output:
	 *	1 2 3 4 
	 *	1 2 3 4 
	 *	a b c 
	 *	a b c 
	 */

	return 0;
}

