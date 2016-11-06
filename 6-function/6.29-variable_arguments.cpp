/* 2016.10.15 10:19
 * P_199
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void error_msg(int e, initializer_list<string> sList)
{
	// whether elem should be reference??
	for (const auto &elem : sList) {
		cout << elem << ' ';
	}
	for (auto elem : sList) {
		cout << elem << ' ';
	}
}

int main(int argc, char **argv)
{
	error_msg(1, {"asd", "fgh", "jkl;"});

	return 0;
}

