/* 2016.11.15 21:19
 * P_301
 * !!!
 * define array: array<int, 3> arr; !!!
 */
#include <iostream>
#include <vector>
#include <array>

using namespace std;

void ShowVector(const vector<int> &vec)
{
	for (const auto i : vec) {
		cout << i << ' ';
	}
	cout << endl;
}
int main(int argc, char **argv)
{
	// 6 types of define
	vector<int> vec0;
	vector<int> vec1(10);
	vector<int> vec2(10, 5);
	vector<int> vec3{1, 2, 3, 4, 5};
	vector<int> vec4(vec3.begin(), vec3.end());
	vector<int> vec5(vec4);

	ShowVector(vec0);
	ShowVector(vec1);
	ShowVector(vec2);
	ShowVector(vec3);
	ShowVector(vec4);
	ShowVector(vec5);

	return 0;
}

