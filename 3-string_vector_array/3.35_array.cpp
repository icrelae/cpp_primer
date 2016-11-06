/* 2016.09.17 20:02
 * P_108
 */
#include <iostream>

int main(int argc, char **argv)
{
	int array[][3] = {{0, 1, 2}, {3, 4, 5}};
	int *p = array[0];
	for (size_t i = 0; i < sizeof(array)/sizeof(int); ++ i)
		*p = 0;
	for (size_t i = 0; i < sizeof(array)/sizeof(int); ++ i)
		std::cout << *p << ' ';

	return 0;
}
