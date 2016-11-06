/* 2016.10.03 11:44
 * P_164
 * getline(cin, string): get whole line except \n from cin
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Enum{
	_Ea,
	_Ee,
	_Ei,
	_Eo,
	_Eu,
	_Espace,
	_Etab,
	_Enewline,
	_Eamount
};
int main(int argc, char **argv)
{
	char ch;
	string str;
	unsigned int counter[_Eamount];
	for (auto &i : counter)
		i = 0;
	while (getline(cin, str)) {
		for (auto i : str)
			switch (i) {
				case 'a':
				case 'A':
					++ counter[_Ea];
					break;
				case 'e':
				case 'E':
					++ counter[_Ee];
					break;
				case 'i':
				case 'I':
					++ counter[_Ei];
					break;
				case 'o':
				case 'O':
					++ counter[_Eo];
					break;
				case 'u':
				case 'U':
					++ counter[_Eu];
					break;
				case ' ':
					++ counter[_Espace];
					break;
				case '\t':
					++ counter[_Etab];
					break;
				case '\n':
					++ counter[_Enewline];
					break;
				default:
					break;
			}
	}

	for (auto i : counter)
		cout << i << ' ';

	return 0;
}
