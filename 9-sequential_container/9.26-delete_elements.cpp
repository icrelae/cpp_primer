/* 2016.11.20 16:13
 * P_312
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char **argv)
{
	list<int> lis;
	vector<int> vec;
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	for (const auto x : ia) {
		vec.push_back(x);
		lis.push_back(x);
	}
	/* wrong procedure, 'it' is invalid after erase !!!
	 *for (vector<int>::const_iterator it = vec.begin(); 
	 *		it < vec.end(); ++it)
	 *	if ((*it % 2) == 0)
	 *	vec.erase(it);
	 */	
	for (vector<int>::const_iterator it = vec.begin(); 
			it < vec.end(); )
		if ((*it % 2) == 0)
			it = vec.erase(it);
		else
			++it;
	for (list<int>::const_iterator it = lis.begin(); 
			it != lis.end(); )
		if ((*it % 2) == 1)
			it = lis.erase(it);
		else
			++it;
	for (auto x : ia)
		cout << x << ' ';
	cout << endl;
	for (auto x : vec)
		cout << x << ' ';
	cout << endl;
	for (auto x : lis)
		cout << x << ' ';

	return 0;
}
