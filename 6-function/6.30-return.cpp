/* 2016.10.15 23:03
 * P_204
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool str_subrange(const string &str1, const string &str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size())
		? str1.size() : str2.size();
	for (decltype(size) i = 0; i != size; ++i) {
		if (str1[i] != str2[i])
			return;
	}
}
int main(int argc, char **argv)
{
	

	return 0;
}

/*
tmp.cpp: In function ‘bool str_subrange(const string&, const string&)’:
tmp.cpp:18:4: error: return-statement with no value, in function returning ‘bool’ [-fpermissive]
    return;
    ^~~~~~
*/
