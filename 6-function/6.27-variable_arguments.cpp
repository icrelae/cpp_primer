/* 2016.10.15 10:19
 * P_199
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Sum(initializer_list<int> iList)
{
	// element of initializer_list<> is all constant!!!
	// iList[1] = 0;	// error
	int sum = 0;
	for (auto it = iList.begin(); it != iList.end(); ++it) {
		sum += *it;
	}
	return sum;
}

int main(int argc, char **argv)
{
	cout << Sum({1, 2, 3, 4, 5, 6, 7, 8, 9});

	return 0;
}

