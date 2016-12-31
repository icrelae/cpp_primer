/* 2016.12.31 16:26
 * P_427
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main(int argc, char **argv)
{
	int *pa = new int[10];
	delete [] pa;
	pa = NULL;

	return 0;
}

