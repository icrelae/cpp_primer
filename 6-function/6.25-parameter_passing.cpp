/* 2016.10.15 10:19
 * P_197
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	if (argc < 3) {
		cout << "at least 2 arguments" << endl;
		return -1;
	}
	string str = argv[1];
	str += argv[2];
	cout << argv[0] << ':' << str;

	return 0;
}

