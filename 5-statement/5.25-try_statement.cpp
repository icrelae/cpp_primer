/* 2016.10.04 22:08
 * P_177
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	double a, b;
	while (cin >> a >> b) {
		try {
			if (b == 0)
				throw 1;
			cout << a/b << endl;
		} catch (int) {
			cout << "b != 0" << endl;
		}
	}

	return 0;
}

