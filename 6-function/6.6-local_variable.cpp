/* 2016.10.04 22:52
 * P_185
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Foo(int par = -1)
{
	int i = 0;
	static int si = 0;
	cout << par++ << endl;
	cout << i++ << endl;
	cout << si++ << endl;

}
int main(int argc, char **argv)
{
	Foo(1);
	Foo(1);
	Foo(1);

	return 0;
}

