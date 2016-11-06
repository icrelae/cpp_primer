/* 2016.10.05 12:46
 * P_190
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main(int argc, char **argv)
{
	int a = 10, b = 80;
	Swap(a, b);
	cout << a << ' ' << b;

	return 0;
}

