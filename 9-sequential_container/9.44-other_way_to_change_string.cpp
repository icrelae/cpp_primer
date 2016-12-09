/* 2016.11.26 18:17
 * P_324
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReplaceStr(string str, string oldStr, string newStr)
{
	while (str.find(oldStr) != string::npos) {
		str.replace(str.find(oldStr), oldStr.size(), newStr);
	}
	return str;
}
int main(int argc, char **argv)
{
	cout << ReplaceStr("asdfasdfasdf", "asd", "123");

	return 0;
}

