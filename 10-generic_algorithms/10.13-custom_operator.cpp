/* 2016.12.13 22:10
 * P_345
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// string size less than 5
bool StrSizeLT5(string const &str)
{
	return (str.size() < 5);
}
int main(int argc, char **argv)
{
	vector<string> vecStr({"12345", "2345", "1234567", "12", "123456", });
	auto itStr = partition(vecStr.begin(), vecStr.end(), StrSizeLT5);
	while (itStr != vecStr.end()) {
		cout << *itStr << ' ';
		++itStr;
	}
	// output: 1234567 12345 123456 

	return 0;
}

