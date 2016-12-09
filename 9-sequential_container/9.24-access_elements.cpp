/* 2016.11.20 15:00
 * P_311
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ShowVecInt(vector<int> vec)
{
	cout << vec.front() << ' ';
	cout << *vec.begin() << ' ';
	cout << vec.at(0) << ' ';
	cout << vec[0] << ' ';
	cout << endl;
}
int main(int argc, char **argv)
{
	vector<int> vec0 = {0, 1, 2, 3}, vec1;
	ShowVecInt(vec0);
	ShowVecInt(vec1);

	return 0;
}
