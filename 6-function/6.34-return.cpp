/* 2016.10.15 23:15
 * P_205
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int factorial1(int val)
{
	if (val > 1)
		return factorial1(val-1) * val;
	return 1;
}
int factorial2(int val)
{
	if (val != 0)
		return factorial2(val-1) * val;
	return 1;
}
int main(int argc, char **argv)
{

	return 0;
}

