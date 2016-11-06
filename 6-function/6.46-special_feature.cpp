/* 2016.10.16 14:42
 * P_215
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr bool isShorter(const string &s1, const string &s2)
{
	// error: call to non-constexpr function!!!
	// all should be const, include parameters
	return s1.size() < s2.size();
}

int main(int argc, char **argv)
{

	return 0;
}

