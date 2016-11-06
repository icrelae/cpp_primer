/* 2016.10.03 11:44
 * P_164
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
	_Eamount
};
int main(int argc, char **argv)
{
	char ch;
	unsigned int counter[_Eamount];
	for (auto &i : counter)
		i = 0;
	while (cin >> ch) {
		switch (ch) {
			case 'a':
				++ counter[_Ea];
				break;
			case 'e':
				++ counter[_Ee];
				break;
			case 'i':
				++ counter[_Ei];
				break;
			case 'o':
				++ counter[_Eo];
				break;
			case 'u':
				++ counter[_Eu];
				break;
			default:
				break;
		}
	}

	for (auto i : counter)
		cout << i << ' ';

	return 0;
}
