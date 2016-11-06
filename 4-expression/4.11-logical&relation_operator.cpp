/* 2016.09.24 19:54
 * P_128
 */
#include <iostream>

void Foo(int a, int b, int c, int d)
{
	std::cout << a << ' ' << b << ' ' << c << ' ' << d << std::endl;
	if (a > b && b > c && c > d)
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;
}
int main(int argc, char **argv)
{
	int a = 2, b = a-1, c = b-1, d = c-1;

	Foo(a, b, c, d);
	Foo(b, a, c, d);
	Foo(c, a, b, d);

	

	return 0;
}

