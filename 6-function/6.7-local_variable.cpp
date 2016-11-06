/* 2016.10.04 22:52
 * P_185
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Foo()
{
	static int si = 0;
	return si ++;
}
int main(int argc, char **argv)
{
	cout << Foo();
	cout << Foo();
	cout << Foo();

	return 0;
}

