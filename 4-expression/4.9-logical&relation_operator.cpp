/* 2016.09.24 19:49
 * P_128
 */
#include <iostream>

int main(int argc, char **argv)
{
	const char *cp = "Hello World";
	if (cp && *cp)
		std::cout << "cp != NULL and *cp != 0";

	return 0;
}

