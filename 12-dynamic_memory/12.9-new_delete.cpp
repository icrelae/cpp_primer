/* 2016.12.29 19:06
 * P_412
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main(int argc, char **argv)
{
	int *q = new int(42), *r = new int(100);
	r = q;

	auto q2 = make_shared<int>(42);
	auto r2 = make_shared<int>(100);
	r2 = q2;

	return 0;
}

