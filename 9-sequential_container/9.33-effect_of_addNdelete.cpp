/* 2016.11.23 23:22
 * P_317
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> vec{0, 1};
	auto begin = vec.begin();
	while (begin != vec.end()) {
		++begin;
		// begin = vec.insert(begin, 42);
		// begin become invalid after insert !!!
		vec.insert(begin, 42);
		++begin;
	}

	return 0;
}
