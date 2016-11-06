/* 2016.10.05 16:39
 * P_192
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool HaveUpper(const string &str)
{
	for (auto c : str)
		if (c >= 'A' || c <= 'Z')
			return true;
	return false;
}
string ToLower(string &str)
{
	for (auto &c : str) {
		if (islower(c))
			continue;
		c = tolower(c);
	}
	return str;
}
int main(int argc, char **argv)
{
	string str1 = "asdf jkl";
	string str2 = "asDF jkl";

	cout << HaveUpper(str1) << endl;
	cout << HaveUpper(str2) << endl;
	cout << ToLower(str1) << endl;
	cout << ToLower(str2) << endl;


	return 0;
}

