/* 2017.03.29 08:47
 * P_638
 * !!!
 * tuple: !!!
 *	header: <tuple>
 *	tuple<T1, T2, ..., Tn> t;
 *	tuple<T1, T2, ..., Tn> t(v1, v2, ..., vn);
 *			// explicit constructor
 *	make_tuple(v1, v2, ..., vn);
 *			// return tuple(v1, ...vn), deduce type
 *	t1 == t2	// have same type and number of members
 *	t1 != t2
 *	t1 relop t2	// relationship op using dictionary order, the number of
 *			// members have to be same
 *	get<i>(t);	// return reference of nth member;
 *			// result is lval if 't' is lval, otherwise result is rval;
 *			// all members of tuple are public;
 *	tuple_size<typeType>::value;
 *			// initiate 'tuple_size' by a 'tuple' type, 'value' means
 *			// number of members in that type
 *	tuple_element<i, tupleType>::type;
 *			// means the type of ith member in tupleType
 */
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

int main(int argc, char **argv)
{
	// both valid
	tuple<int, int, int> t1a(10, 20, 30);
	tuple<int, int, int> t1b{10, 20, 30};

	tuple<string, vector<string>, pair<string, int>> t2;

	return 0;
}

