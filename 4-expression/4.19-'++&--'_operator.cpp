/* 2016.09.24 21:10
 * P_133
 */
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	int *ptr, ival;
	std::vector<int> vec;

	ptr != 0 && *ptr++;

	ival++ && ival;
	// error

	vec[ival++] <= vec[ival];
	// error

	return 0;
}

