/* 2017.01.12 20:13
 * P_481
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

unique_ptr<int> clone(int p)
{
	return unique_ptr<int>(new int(p));
}

int main(int argc, char **argv)
{
	unique_ptr<int> p1(new int(1));
	unique_ptr<int> p2(p1.release());
	unique_ptr<int> p3(new int(3));
	//p2 = p3;	// assignment is invalid
	p2.reset(p3.release());
	p2 = clone(4);	// valid, because here is using rlvalue, move it

	return 0;
}
