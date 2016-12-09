/* 2016.11.19 16:12
 * P_309
 * insert operation cause invalid of iter
 */
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

using namespace std;

int main(int argc, char **argv)
{
	int some_val = 4;
	vector<int> iv = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int>::iterator iter = iv.begin(), 
		mid = iv.begin() + iv.size()/2;
	while (iter != mid)
		if (*iter == some_val)
			// iv.insert(iter, 2 * some_val);
			iter = iv.insert(iter, 2 * some_val);

	return 0;
}

