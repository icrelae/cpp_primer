/* 2016.12.14 22:35
 * P_349
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	unsigned sizeStr = 3;
	vector<string> vecStr({"1sdf", "2f", "3df", "3f", "4sdf", "5"});
	for_each(vecStr.begin(), vecStr.end(), 
			[sizeStr] (string const &str) {
			if (str.size() > sizeStr)
				cout << str << ' ';
			});

	return 0;
}

