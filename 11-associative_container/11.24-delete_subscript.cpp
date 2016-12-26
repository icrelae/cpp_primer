/* 2016.12.26 18:45
 * P_388
 * !!!
 * delete: !!!
 * c.erase(it): return iterator of element after '*it'
 * c.erase(itBeg, itEnd): return 'itEnd'
 * c.erase(key_type): return number of deleted elements
 * subscript: !!!
 * for 'map' and 'unordered_map':
 * c[key_type k]: if 'k' is not existent, insert it
 * c.at(key_type k): if 'k' is not existent, throw exception "out_of_range"
 * subcription return a left-value, means it could be assigned so it have to be non-constant
 */
#include <iostream>
#include <string>
#include <map>
#include <typeinfo>

using namespace std;

void DeleteEG()
{
	map<int, int> m({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
	auto t = m.erase(m.begin());
	cout << typeid(t).name() << ' ' << t->first << endl;
	// output: St17_Rb_tree_iteratorISt4pairIKiiEE 2
}

int main(int argc, char **argv)
{
	DeleteEG();
	
	map<int, int> m;
	// insert pair<int, int>(0, 1)
	m[0] = 1;

	return 0;
}

