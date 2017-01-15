/* 2017.01.15 15:23
 * P_493
 * member or not:
 * = [] () ->: have to be member of a class
 * += -= *= /= ^= %= >>= <<=: should be member generally
 * operators change obj's state like ++ -- *ptr should be member
 * symmetrical operators like + == & shouldn't be member
 *
 * %	non-member
 * %=	member
 * ++	member
 * ->	member
 * <<	member
 * &&	non-member
 * ==	non-member
 * ()	member
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{

	return 0;
}

