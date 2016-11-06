/* 2016.10.15 10:19
 * P_199
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void error_msg(int e, initializer_list<string> sList)
{
	// type of elem is string?
	for (const auto &elem : sList)
		cout << elem << ' ';
}

int main(int argc, char **argv)
{

	return 0;
}

