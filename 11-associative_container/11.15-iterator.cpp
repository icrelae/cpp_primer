/* 2016.12.25 11:40
 * P_383
 * !!!
 * type member: !!!
 *	kye_type: type of key
 *	mapped_type: only map have, type of value associated to key
 *	value_type:
 *		for set, same with key_type
 *		for map, 'pair<const key_type, mapped_type>'
 * both iterator and const_iterator of set are constant !!!
 * don't using generic-algs on associative container generally !!!
 *	associative container has a find() as it's own member function
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <typeinfo>

using namespace std;

int main(int argc, char **argv)
{
	using m=map<int, vector<int>>;
	cout << typeid(m::mapped_type).name() << ' ';	// vector<int>
	cout << typeid(m::key_type).name() << ' ';	// int
	cout << typeid(m::value_type).name() << ' ';	// pair<int, vector<int>>
	// output: St6vectorIiSaIiEE i St4pairIKiSt6vectorIiSaIiEEE 

	return 0;
}

