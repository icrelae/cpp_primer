/* 2016.10.15 23:15
 * P_205
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void DisplayRecursive(vector<int> vec, vector<int>::size_type index)
{
	if (index < 1)
		return;
	DisplayRecursive(vec, index-1);
	cout << vec[index-1] << ' ';
}
int main(int argc, char **argv)
{
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7};
	DisplayRecursive(vec, vec.size());

	return 0;
}

