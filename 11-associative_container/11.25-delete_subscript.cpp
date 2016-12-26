/* 2016.12.26 18:45
 * P_388
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
	// insert pair<int, int>(0, 1)
	m[0] = 1;

	vector<int> v;
	// invalid, v is empty
	v[0] = 1;

	return 0;
}

