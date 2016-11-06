/* 2016.10.15 23:15
 * P_205
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int factorial(int val)
{
	if (val > 1)
		// undefined conduct
		return factorial(val--) * val;
	return 1;
}
int main(int argc, char **argv)
{

	return 0;
}

