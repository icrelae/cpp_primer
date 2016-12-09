/* 2016.11.27 12:50
 * P_327
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsAscender(const string str)
{
	static const string ascender = "bdfhijklt";
	if (str.find_first_of(ascender) == string::npos)
		return false;
	else
		return true;
}
bool IsDescender(const string str)
{
	static const string descender = "gjpqy";
	if (str.find_first_of(descender) == string::npos)
		return false;
	else
		return true;
}
string FindLongestValidWord(istream &is)
{
	string str;
	string maxSizeStr("");
	while (is >> str) {
		if (!(IsAscender(str) || IsDescender(str)) &&
			(str.size() > maxSizeStr.size()))
			maxSizeStr = str;
	}
	return maxSizeStr;
}

int main(int argc, char **argv)
{
	cout << FindLongestValidWord(cin);

	return 0;
}

