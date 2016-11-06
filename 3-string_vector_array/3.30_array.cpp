/* 2016.09.04 14:40
 * P_104
 */
#include <iostream>

int main(int argc, char **argv)
{
	constexpr size_t array_size = 10;
	int ia[array_size];
	for (size_t ix = 1; ix <= array_size; ++ ix)
		ia[ix] = ix;

	return 0;
}

/* index 'ix' out of boundary
 */
