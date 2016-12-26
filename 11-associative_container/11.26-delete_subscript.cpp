/* 2016.12.26 18:45
 * P_388
 * type of subscript: decltype(map)::key_type
 * type of returned: decltype(map)::mapped_type
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <typeinfo>

using namespace std;

int main(int argc, char **argv)
{
	map<int, int> m;

	decltype(m)::key_type first;
	for (first = 0; first < 4; ++first)
		m[first] = first + 1;

	return 0;
}

