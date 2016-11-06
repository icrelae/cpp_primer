/* 2016.11.06 10:35
 * P_272
 * !!!
 * location of definition of static data member: !!!
 * 1) best in the same file with other non-inline function
 * condition of inner-class defination of static data member: !!!
 * 1) type of data member should be 'constexpr'
 * 2) initialization value should be const expression
 */
#include <iostream>
#include <string>
#include <vector>
#include "tmp.h"

using namespace std;

double Example::rate = 6.5;
vector<double> Example::vec(Example::vecSize);

int Example::Foo()
{
	return 0;
}

