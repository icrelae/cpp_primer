/* 2017.03.19 16:59
 * P_607
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// set return type which is big enough for any result of 'sum' !!!
template<typename T1, typename T2>
auto sum(const T1 &lhs, const T2 &rhs) -> decltype(lhs + rhs)
{
	return lhs + rhs;
}

int main(int argc, char **argv)
{

	return 0;
}

