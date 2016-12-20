/* 2016.12.20 21:29
 * P_354
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	int i = 5;
	auto lmd1021 = [&i] () -> bool {
		if (i > 0)
			--i;
		if (i == 0)
			return true;
		else
			return false;
	};
	while (i > 0)
		cout << lmd1021() << ' ';
	cout << lmd1021();
	// output: 0 0 0 0 1 1

	return 0;
}

