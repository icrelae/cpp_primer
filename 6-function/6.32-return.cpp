/* 2016.10.15 23:13
 * P_204
 * valid function
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int &get(int *array, int index)
{
	return array[index];
}

int main(int argc, char **argv)
{
	int ia[10];
	for (int i = 0; i != 10; ++i)
		get(ia, i) = i;

	return 0;
}

