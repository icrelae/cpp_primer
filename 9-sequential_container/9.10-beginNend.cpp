/* 2016.11.15 21:19
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> v1;
	const vector<int> v2;

	// vector<int>::iterator
	auto it1 = v1.begin();
	// vector<int>::const_iterator
	auto it2 = v2.begin();
	// vector<int>::const_iterator
	auto it3 = v1.cbegin();
	// vector<int>::const_iterator
	auto it4 = v2.cbegin();

	return 0;
}

