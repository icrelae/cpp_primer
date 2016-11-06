/* 2016.10.16 16:10
 * P_223
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Foo(int, int)
{
	return 0;
}
vector<int (*)(int, int)> vec = {Foo};

int main(int argc, char **argv)
{

	return 0;
}

