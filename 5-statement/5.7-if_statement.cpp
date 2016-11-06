/* 2016.09.29 23:04
 * P_159
 */
#include <iostream>

int get_value()
{
	return 0;
}
int main(int argc, char **argv)
{
	int ivala1, ivala2;

	// (a)
	if (ivala1 != ivala2)
		ivala1 = ivala2;
	else
		ivala1 = ivala2 = 0;

	// (b)
	int  ivalb, minval, occurs;
	if (ivalb < minval) {
		minval = ivalb;
		occurs = 1;
	}

	// (c)
	int ivalc;
	if (ivalc = get_value())
		std::cout << "ivalc = " << ivalc << std::endl;
	if (!ivalc)
		std::cout << "ivalc = 0\n";

	// (d)
	int ivald;
	if (ivald == 0)
		ivald = get_value();

	return 0;
}

