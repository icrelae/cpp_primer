/* 2017.03.22 09:09
 * P_618
 * !!!
 * type transformation can be used in function template: !!!
 *	1. const transform: passing 'non-const *|&' to a 'const *|&'
 *	2. array or pointer transform: if parameter is not reference, then
 *	'array arg' or a 'function arg' an transform to a 'pointer'
 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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
/*
string debug_rep(const string &s)
{
	return '"' + s + '"';
}
*/
void RelaodTemplateEG()
{
	string s("hi");
	cout << debug_rep(s) << endl;	// call first, but third will be called if it defined
	cout << debug_rep(&s) << endl;	// call second

	const string *sp = &s;
	cout << debug_rep(sp) << endl;
	/* here call second 'debug_rep', 'const T&' can be used for any type,
	 * more general than 'T*', so compiler choose more narrower
	 */

	cout << debug_rep("123456789") << endl;
	/* for 'debug_rep(const T&)', 'T' is 'char[10]';
	 * for 'debug_rep(T*)', 'T' is 'const char';
	 * for 'debug_rep(const string&)', need transform 'const char*' to
	 * 'const string';
	 * here will call narrowest one, the second
	 */
}

template<typename T> void f(T)
{
	cout << "first f()" << endl;
}
template<typename T> void f(const T*)
{
	cout << "second f()" << endl;
}
template<typename T> void g(T)
{
	cout << "first g()" << endl;
}
template<typename T> void g(T*)
{
	cout << "second g()" << endl;
}

int main(int argc, char **argv)
{
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	f(42);	// call first, T: int
	f(p);	// call first, T: int*
	f(ci);	// call first, T: int
	f(p2);	// call second, T: int
	g(42);	// call first, T: int
	g(p);	// call second, T: int
	g(ci);	// call first, T: int
	g(p2);	// call second, T: const int
	/* output:
	 *	first f()
	 *	first f()
	 *	first f()
	 *	second f()
	 *	first g()
	 *	second g()
	 *	first g()
	 *	second g()
	 */

	return 0;
}

