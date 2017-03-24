/* 2017.03.23 09:13
 * P_622
 * !!!
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
string debug_rep(const T&t)
{
	ostringstream ret;
	ret << t;
	return ret.str();
}
template<typename T>
ostream& print(ostream &os, const T &t)
{
	return os << t << ' ';
}
template<typename T, typename... Rest>
ostream& print(ostream &os, const T &t, const Rest&... rest)
{
	os << t << ' ';
	return print(os, rest...);
}
template<typename ... Args>
ostream& errorMsg(ostream &os, const Args& ... rest)
{
	/* package expand: !!!
	 * print(os, debug_rep(a1), debug_rep(a2), ..., debug_rep(an))
	 */
	return print(os, debug_rep(rest)...);
	/* invalid: print(os, debug_rep(a1, a2, ..., an))
	 * return print(os, debug_rep(rest...))
	 */
}

void error_msg(initializer_list<string> il)
{
	for (auto beg = il.begin(); beg != il.end(); ++beg)
		cout << *beg << " ";
	cout << endl;
}

int main(int argc, char **argv)
{
	//error_msg(cout, 1, 2.2, '3', "4");	// only string can be passed
	errorMsg(cout, 1, 2.2, '3', "4");

	return 0;
}

