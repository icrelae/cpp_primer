/* 2017.02.15 22:02
 * P_521
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct LongDouble {
	LongDouble (double = 0.0);
	operator double();
	operator float();
};

void calc(int) { }
void calc(LongDouble) { }

int main(int argc, char **argv)
{
	double dval = 0;
	calc(dval);	// calc(LongDouble(dval))

	return 0;
}

