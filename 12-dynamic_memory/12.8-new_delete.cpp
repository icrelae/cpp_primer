/* 2016.12.29 19:06
 * P_411
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

bool b()
{
	// memory leak
	int *p = new int;
	return p;
}
int main(int argc, char **argv)
{

	return 0;
}

