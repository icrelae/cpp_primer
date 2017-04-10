/* 2017.04.10 20:44
 * P_686
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	range_error r("error");
	if (0)
		throw r;	// range_error
	exception *p = &r;
	if (0)
		throw *p;	// range_error

	return 0;
}

