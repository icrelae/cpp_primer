/* 2016.12.21 22:08
 * P_357
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool CheckStrSize(string const &str, string::size_type const size)
{
	return str.size() > size;
}

int main(int argc, char **argv)
{
	string str("12345");
	vector<int> vecInt({8, 7, 6, 5, 4, 3, 2, 1});
	cout << *find_if(vecInt.begin(), vecInt.end(),
			bind(CheckStrSize, str, _1));
	// output: 4

	return 0;
}

