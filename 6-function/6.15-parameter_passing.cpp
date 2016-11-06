/* 2016.10.05 16:03
 * P_190
 *
 * 1
 * s is const string & to prevent from string copy and string change unintentional
 * occurs is size_type & to return value of occur times
 * 2
 *
 * 3
 * string copy
 * 4
 * unable to change occrus value
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string::size_type find_char(const string &s, char c, 
		string::size_type &occurs)
{
	auto ret = s.size();
	occurs = 0;
	for (decltype(ret) i = 0; i != s.size(); ++i) {
		if (s[i] == c) {
			if (ret == s.size())
				ret = i;
			++occurs;
		}
	}
	return ret;
}
int main(int argc, char **argv)
{

	return 0;
}

