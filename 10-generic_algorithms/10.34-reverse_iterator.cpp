/* 2016.12.23 21:16
 * P_365
 * !!!
 * all container support reverse-iterator except forward_list !!!
 * reverseIterator.base(): return normal iterator !!!
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void ReverseIteratorEG()
{
	vector<int> vecInt1({4, 2, 1, 3, 2, 5, 3});
	vector<int> vecInt2({4, 2, 1, 3, 2, 5, 3});
	sort(vecInt1.begin(), vecInt1.end());
	// using reverse-iterator to sort decrease
	sort(vecInt2.rbegin(), vecInt2.rend());
	for (auto const &num : vecInt1)
		cout << num << ' ';
	cout << endl;
	// output: 1 2 2 3 3 4 5 
	for (auto const &num : vecInt2)
		cout << num << ' ';
	cout << endl;
	// output: 5 4 3 3 2 2 1 
}
int main(int argc, char **argv)
{
	ReverseIteratorEG();
	vector<int> vecInt({1, 2, 3, 4, 5, 6});
	for_each(vecInt.crbegin(), vecInt.crend(),
			[] (int const &x) {cout << x << ' ';});
	// output: 6 5 4 3 2 1 

	return 0;
}

