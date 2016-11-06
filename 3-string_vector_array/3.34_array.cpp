/* 2016.09.17 20:02
 * P_108
 * 1)	p1 += p2 - p1 equals to 
 *	p1 = p2 ?
 * 2)	??
 */
#include <iostream>

int main(int argc, char **argv)
{
	int array[][3] = {{0, 1, 2}, {3, 4, 5}};
	int *p1 = array[0]+2, *p2 = array[1]+1;

	p1 += p2 - p1;
	std::cout << *p1 << ' ' << *p2;

	return 0;
}
