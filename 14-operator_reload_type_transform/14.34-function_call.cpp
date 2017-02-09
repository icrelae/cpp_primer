/* 2017.02.09 22:14
 * P_507
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Foo {
	public:
		int operator()(int a, int b, int c)
		{
			if (a != 0)
				return b;
			else
				return c;
		}
};

int main(int argc, char **argv)
{
	Foo foo;
	cout << foo(1, 2, 3);
	cout << foo(0, 2, 3);
	// output: 23

	return 0;
}

