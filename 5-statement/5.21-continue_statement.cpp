/* 2016.10.04 21:19
 * P_171
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	string str, buf;
	while (cin >> buf) {
		if (buf[0] < 'A' || buf[0] > 'Z')
			continue;
		if (buf == str)
			break;
		str = buf;
	}
	if (cin)
		cout << buf;
	else
		cout << "no repeat";

	return 0;
}

