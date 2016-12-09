/* 2016.11.14 21:03
 * P_297
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Search(vector<int>::const_iterator a, 
		vector<int>::const_iterator b, 
		const int target)
{
	if (a > b) {
		vector<int>::const_iterator tmp = a;
		a = b;
		b = tmp;
	}
	while (a <= b) {
		if (*a++ == target)
			return true;
	}
	return false;
}
int main(int argc, char **argv)
{
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6};
	vector<int>::const_iterator a = vec.begin() + 4;
	vector<int>::const_iterator b = vec.begin();
	cout << Search(a, b, 0);
	cout << Search(b, a, 0);
	cout << Search(a, b, 1);
	cout << Search(b, a, -1);

	return 0;
}

