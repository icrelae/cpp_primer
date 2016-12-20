/* 2016.12.13 21:59
 * P_342
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

void A()
{
	vector<int> vec;
	list<int> lst({1, 2, 3, 4, 5, 6, 7});
	//copy(lst.cbegin(), lst.cend(), vec.begin());
	copy(lst.cbegin(), lst.cend(), back_inserter(vec));
	for (auto intNum : vec)
		cout << intNum << ' ';
	// output: 1 2 3 4 5 6 7 
}
void B()
{
	vector<int> vec;
	vec.reserve(10);
	fill_n(vec.begin(), 10, 0);
	for (auto intNum : vec)
		cout << intNum << ' ';
	// output: (nothing)
	// because vec.size() = 0
}
int main(int argc, char **argv)
{

	return 0;
}

