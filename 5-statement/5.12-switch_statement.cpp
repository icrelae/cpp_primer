/* 2016.10.03 11:44
 * P_164
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum {
	_Eff,
	_Efl,
	_Efi,
	_Eamount
};
int main(int argc, char **argv)
{
	string str;
	unsigned int counter[_Eamount];
	for (auto &i : counter)
		i = 0;
	while (getline(cin, str)) {
		if (str.size() != 2 || str[0] != 'f')
			continue;
		switch (str[1]) {
			case 'f':
				++ counter[_Eff];
				break;
			case 'l':
				++ counter[_Efl];
				break;
			case 'i':
				++ counter[_Efi];
				break;
			default:
				break;
		}
	}

	for (auto i : counter)
		cout << i << ' ';

	return 0;
}
