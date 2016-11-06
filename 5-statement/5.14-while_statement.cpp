/* 2016.10.04 14:58
 * P_166
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	string str, buf, cmaxstr;
	unsigned int counter = 1, cmax = 1;
	
	while (cin >> buf) {
		if (buf == str) {
			++ counter;
		} else {
			cmaxstr = counter > cmax ? str : cmaxstr;
			cmax = counter > cmax ? counter : cmax;
			counter = 1;
			str = buf;
		}
	}
	cout << cmaxstr << ' ' << cmax;

	return 0;
}

