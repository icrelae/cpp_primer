/* 2017.01.12 08:39
 * P_472
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	int f();
	vector<int> vi(100);

	int &&r1 = f();
	int &r2 = vi[0];
	int &r3 = r1;
	int &&r4 = vi[0] * f();

	return 0;
}

