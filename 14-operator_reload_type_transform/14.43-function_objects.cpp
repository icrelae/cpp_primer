/* 2017.02.14 22:52
 * P_510
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> vecInt{1, 2, 3, 4, 5};
	modulus<int> mod;
	for (auto x : vecInt) {
		if (mod(x, 2) != 0)
			cout << x << " no" << endl;
		else
			cout << x << " yes" << endl;
	}
	/* output:
	 *	1 no
	 *	2 yes
	 *	3 no
	 *	4 yes
	 *	5 no
	 */

	return 0;
}

