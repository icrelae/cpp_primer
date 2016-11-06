/* 2016.10.04 21:17
 * P_170
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	string str1, str2;
	do {
		cin >> str1 >> str2;
		cout << (str1.size() < str2.size() ? str1 : str2) << endl;
	} while (cin);

	return 0;
}

