/* 2016.11.23 23:22
 * P_317
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> vec{0, 1, 2, 3, 4, 5};
	auto iter = vec.begin();
	while (iter != vec.end()) {
		if (*iter % 2)
			iter = vec.insert(iter, *iter);
		++iter;
		/* double event number, but infinite loop
		 * instead '++iter' with 'iter += 2'
		 */
	}

	return 0;
}
