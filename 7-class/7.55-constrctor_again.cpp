/* 2016.11.03 21:46
 * P_268
 * !!!
 * no, condition of constexpr class:!!!
 * 1) all data member should be literal value
 * 2) one constexpr constructor at least
 * 3) initial value should be constexpr if there is a data member 
 * which has inner-class initial value
 * 4) using default destructor
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Data {
	int ival;
	string s;
};

int main(int argc, char **argv)
{

	return 0;
}
