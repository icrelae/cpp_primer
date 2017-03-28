/* 2017.03.28 09:55
 * P_622
 *
 * overload chages the template match !!!
 * template specialization initiate a template, won't affect matching !!!
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
string debug_rep(const T &p)
{
	ostringstream ret;
	ret << p;
	return ret.str();
}
template<typename T>
string debug_rep(T *p)
{
	ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}
template<>
string debug_rep(const char* cp)
{
	string str(cp);
	return str;
}
template<>
string debug_rep(char* cp)
{
	string str(cp);
	return str;
}

int main(int argc, char **argv)
{
	char cstr[] = "asdf", *cp = cstr;
	const char *ccp = cstr;
	// without 'debug_rep(char*)' here will match 'debug_rep(T*)'
	cout << debug_rep(cp);
	// here match 'debug_rep(const char*)'
	cout << debug_rep(ccp);

	return 0;
}

