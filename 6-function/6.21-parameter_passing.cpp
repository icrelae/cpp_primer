/* 2016.10.13 23:02
 * P_196
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int MaxInt(int a, const int *b)
{
	return (a > *b ? a : *b);
}
int main(int argc, char **argv)
{
	int a = 3, b = 2;
	cout << MaxInt(a, &b);

	return 0;
}

