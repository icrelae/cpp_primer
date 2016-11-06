/* 2016.10.04 22:44
 * P_184
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned int Fact(unsigned x)
{
	if (x <= 1)
		return 1;
	return (x * Fact(x-1));
}

int main(int argc, char **argv)
{
	cout << Fact(5);

	return 0;
}

