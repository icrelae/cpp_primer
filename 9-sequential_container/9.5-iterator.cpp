/* 2016.11.14 21:03
 * P_297
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int>::const_iterator Search(vector<int>::const_iterator a, 
		vector<int>::const_iterator b, 
		const int target)
{
	if (a > b) {
		vector<int>::const_iterator tmp = a;
		a = b;
		b = tmp;
	}
	while (a <= b) {
		if (*a == target)
			break;
		++a;
	}
	return a;
}
int main(int argc, char **argv)
{
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6};
	vector<int>::const_iterator a = vec.begin() + 4;
	vector<int>::const_iterator b = vec.begin();
	int target = 3;
	if (*(Search(a, b, target)) == target)
		cout << "yes";
	else
		cout << "no";

	return 0;
}

