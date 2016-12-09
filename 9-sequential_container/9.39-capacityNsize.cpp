/* 2016.11.24 21:41
 * P_320
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<string> svec;
	svec.reserve(1024);
	string word;
	while (cin >> word)
		svec.push_back(word);
	svec.resize(svec.size() + svec.size() / 2);

	return 0;
}

