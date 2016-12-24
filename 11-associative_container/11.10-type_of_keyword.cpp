/* 2016.12.24 21:00
 * P_379
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	// valid
	map<vector<int>::iterator, int> map1;
	// invalid, because list::iterator have no '<' operator
	map<list<int>::iterator, int> map2;

	return 0;
}

