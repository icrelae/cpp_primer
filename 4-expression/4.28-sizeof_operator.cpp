/* 2016.09.25 12:41
 * P_140
 */
#include <iostream>

#define __SHOWSIZE(type) std::cout << #type << ": " << sizeof(type) << std::endl;
#define _SHOWSIZE() \
	__SHOWSIZE(char) \
	__SHOWSIZE(short) \
	__SHOWSIZE(int) \
	__SHOWSIZE(long) \
	__SHOWSIZE(long long) \
	__SHOWSIZE(char *) \
	__SHOWSIZE(int *) \
	__SHOWSIZE(int **)

int main(int argc, char **argv)
{
	_SHOWSIZE();

	return 0;
}

