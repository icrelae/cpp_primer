/* 2016.09.18 22:30
 * P_110
 * display ca until *cp == 0
 */
#include <iostream>

int main(int argc, char **argv)
{
	const char ca[] = {'h', 'e', 'l', 'l', 'o'};
	const char *cp = ca;
	while (*cp) {
		std::cout << *cp;
		++ cp;
	}

	return 0;
}

