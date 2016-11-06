/* 2016.10.05 12:42
 * P_188
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Swap(int *a, int *b)
{
	if (a == NULL || b == NULL)
		return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int main(int argc, char **argv)
{
	int a = 10, b = 80;
	Swap(&a, &b);
	cout << a << ' ' << b;

	return 0;
}

