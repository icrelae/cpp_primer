/* 2016.10.04 21:09
 * P_170
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	// (a)
	do {
		int v1, v2;
		cout << "please enter two numbers to sum:";
		if (cin >> v1 >> v2)
			cout << "sum is:" << v1 + v2 << endl;
	} while (cin);

	// (b)
	int ivalb;
	do {
	} while (ivalb = get_response());

	// (c)
	int ivalc;
	do {
		ivalc = get_response();
	} while (ivalc);

	return 0;
}

