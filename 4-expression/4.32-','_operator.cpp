/* 2016.09.25 15:22
 * P_141
 */
#include <iostream>

int main(int argc, char **argv)
{
	constexpr int size = 5;
	int ia[size] = {1, 2, 3, 4, 5};
	
	for (int *ptr = ia, ix = 0;
			ix != size && ptr != ia+size;
			++ix, ++ptr) {
		std::cout << ia[ix] << ' ' << *ptr << std::endl;
	}
	// ix from 0 to 4
	// ptr from &ia[0] to &ia[4]

	return 0;
}

