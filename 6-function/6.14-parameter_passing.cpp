/* 2016.10.05 12:50
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

int Fact(int a)
{
	if (a <= 1)
		return 1;
	return (a * Fact(a-1));
}

int main(int argc, char **argv)
{

	return 0;
}

