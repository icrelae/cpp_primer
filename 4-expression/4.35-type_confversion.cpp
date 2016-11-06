/* 2016.09.25 15:38
 * P_143
 */
#include <iostream>

int main(int argc, char **argv)
{
	char cval;
	int ival;
	unsigned int ui;
	float fval;
	double dval;

	cval = 'a' + 3;
	fval = ui - ival * 1.0;	// int to double to unsigned int
	dval = ui * fval;	// int to float to double
	cval = ival + fval + dval;	// int to float to double to char

	return 0;
}

