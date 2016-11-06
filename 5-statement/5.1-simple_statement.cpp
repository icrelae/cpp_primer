/* 2016.09.27 23:36
 * P_155
 */
#include <iostream>

int main(int argc, char **argv)
{
	char array1[] = "hello world ...", array2[20];
	char *p1 = array1, *p2 = array2;

	while (*p2++ = *p1++);
	std::cout << array2 << '#';

	return 0;
}

