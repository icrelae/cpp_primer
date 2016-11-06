/* 2016.10.15 23:09
 * P_204
 * 1) local variable
 * 2) return noconst
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int &Foo1()
{
	int i = 1;
	return i;
}
int &Foo2()
{
	const int a = 1;
	return a;
}

int main(int argc, char **argv)
{

	return 0;
}

