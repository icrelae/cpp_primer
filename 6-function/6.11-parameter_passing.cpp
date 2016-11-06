/* 2016.10.05 12:46
 * P_190
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reset(int &a)
{
	a = 0;
}
int main(int argc, char **argv)
{
	int a = 10;
	reset(a);
	cout << a;

	return 0;
}

