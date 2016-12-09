/* 2016.11.26 17:29
 * P_322
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Method0()
{
	vector<string> vecStr(100, " ");
	string buffer;
	cin >> buffer;
	for (vector<string>::size_type i = 0; i <= buffer.size(); ++i)
		vecStr[i] = buffer.substr(i, 1);
}

void Method1()
{
	vector<string> vecStr;
	vecStr.reserve(100);
	string buffer;
	cin >> buffer;
	for (vector<string>::size_type i = 0; i <= buffer.size(); ++i)
		vecStr.emplace_back(buffer.substr(i, 1));
}
int main(int argc, char **argv)
{
	return 0;
}
