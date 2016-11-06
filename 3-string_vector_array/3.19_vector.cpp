/* 2016.08.28 15:19
 * P_94
 * three way to create a vector contains 10 '42'
 */
#include <iostream>
#include <vector>

using std::vector;

int main(int argc, char **argv)
{
	vector<int> ivec1(10, 42);
	vector<int> ivec2 = {42, 42, 42, 42, 42, 42, 42, 42 ,42, 42};
	vector<int> ivec3 = ivec2;

	vector<vector<int>> ivec{ivec1, ivec2, ivec3};
	for (auto &i : ivec) {
		for (auto &j : i)
			std::cout << j << ' ';
		std::cout << std::endl;
	}

	return 0;
}

