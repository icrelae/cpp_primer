/* 2016.09.24 17:19
 * P_126
 * check a int whether odd or even
 */
#include <iostream>

int main(int argc, char **argv)
{
	srandom(time(NULL));
	int a = random();
	std::cout << a << " : " << (a % 2 ? "odd" : "double");

	return 0;
}

