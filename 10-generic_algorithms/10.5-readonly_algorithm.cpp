/* 2016.12.11 22:59
 * P_339
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, char **argv)
{
	string str1 = "a";
	string str2 = "a";
	vector<const char *> vecChaPtA({str1.c_str()});
	vector<const char *> vecChaPtB({str2.c_str()});
	// compare 'char *'
	cout << equal(vecChaPtA.begin(), vecChaPtA.end(), vecChaPtB.begin());

	return 0;
}

