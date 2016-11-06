/* 2016.08.28 14:39
 * P_94
 * various way of initialize of vector
 */
#include <iostream>
#include <vector>

using std::vector;
using std::string;

int main(int argc, char **argv)
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{10};
	vector<int> v5{10, 42};
	vector<int> v6{10};
	vector<vector<int>> vi = {v1, v2, v3, v4, v5, v6};
	vector<string> v7{10, "hi"};

	vector<vector<int>>::size_type i_vi;
	for (i_vi = 0; i_vi < vi.size(); ++ i_vi) {
		std::cout << vi[i_vi].size() << std::endl;
		vector<int>::size_type i_v;
		for (i_v = 0; i_v < vi[i_vi].size(); ++ i_v)
			std::cout << vi[i_vi][i_v] << ' ';
		std::cout << std::endl;
	}


	return 0;
}
