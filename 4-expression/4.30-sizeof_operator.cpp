/* 2016.09.25 13:19
 * P_140
 */
#include <iostream>

struct Foo
{
	int mem[10];
};
int f() {};
int main(int argc, char **argv)
{
	int x = 3, y = 4, i = 0;
	struct Foo *p = NULL;

	std::cout << sizeof x + y << std::endl;		// 8
	std::cout << sizeof(x) + y << std::endl;	// 8

	std::cout << sizeof p->mem[i] << std::endl;	// 4
	std::cout << sizeof(p->mem[i]) << std::endl;	// 4

	std::cout << (sizeof x < y) << std::endl;	// 0
	std::cout << ((sizeof x) < y) << std::endl;	// 0

	std::cout << sizeof f() << std::endl;		// 4
	std::cout << sizeof(f()) << std::endl;		// 4

	return 0;
}
