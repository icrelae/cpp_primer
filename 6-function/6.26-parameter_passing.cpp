/* 2016.10.15 10:19
 * P_197
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	int i = 1;
	while (i < argc) {
		cout << argv[i] << endl;
		++i;
	}
	return 0;
}

