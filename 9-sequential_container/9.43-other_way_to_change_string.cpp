/* 2016.11.26 18:17
 * P_324
 * !!!
 * insert() and erase() for string: !!!
 * s.insert(s.size(), 5, '!'): insert 5 '!' at the end of s
 * s.erase(s.size() - 5, 5): erase last 5 characters of s
 * assign() for string: !!!
 * const char *cp = "stately, plump buck";
 * s.assign(cp, 7);		// "stately"
 * s.insert(s.size(), cp+7);	// "stately, plump buck"
 * s.assign(cp, n): strictly assign s using n charactors, so n have to be less than size of cp
 * append() and replace() for string: !!!
 * s = "01234";
 * s.append("567");		// "01234567"
 * s.replace(1, 3, "asd");	// "0asd4567"
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReplaceStr(string str, string oldStr, string newStr)
{
	string::size_type posOfOldStr = str.find(oldStr);
	while (posOfOldStr != string::npos) {
		str.erase(posOfOldStr, oldStr.size());
		str.insert(posOfOldStr, newStr);
		posOfOldStr = str.find(oldStr);
		//str.replace(str.find(oldStr), oldStr.size(), newStr);
	}
	return str;
}
int main(int argc, char **argv)
{
	cout << ReplaceStr("asdfasdfasdf", "asd", "123");

	return 0;
}

