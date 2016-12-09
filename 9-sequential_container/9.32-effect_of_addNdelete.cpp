/* 2016.11.23 23:22
 * P_317
 * ???
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> vec{0, 1};
	auto iter = vec.begin();
	// undefined behavior ???
	iter = vec.insert(iter, *iter++);

	return 0;
}
