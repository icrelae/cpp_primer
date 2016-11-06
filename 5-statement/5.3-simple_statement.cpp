/* 2016.09.27 23:57
 * P_155
 */
#include <iostream>

int main(int argc, char **argv)
{
	int sum = 0, val = 1;

	while (val <= 10)
		sum += val, ++val;
	std::cout << "sum of 1 to 10 inclusive is "
		<< sum << std::endl;

	return 0;
}

