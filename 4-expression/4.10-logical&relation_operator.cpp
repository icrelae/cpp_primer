/* 2016.09.24 19:50
 * P_128
 */
#include <iostream>

int main(int argc, char **argv)
{
	int a;
	while ((std::cin >> a) && a != 42) {
		std::cout << "input 42 to stop the loop" << std::endl;
	}


	return 0;
}

