/* 2017.03.23 08:43
 * P_619
 * !!!
 * parameter packet: !!!
 *	template parameter packet <typename... Args>
 *	function parameter packet (Args ... paras)
 *	sizeof...(Args): return number of parameters in 'Args'
 *	sizeof...(paras): return number of parameters in 'paras'
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T, typename ... Args>
void foo(const T &t, const Args& ... args)
{
	cout << sizeof...(Args) << ' ';
	cout << sizeof...(args) << endl;
	// Eoo("1st arg", args...);
}

int main(int argc, char **argv)
{
	int i = 0;
	double d = 3.14;
	string s = "how now brown cow";
	foo(i, s, 42, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo(d, s, s);
	foo("hi");
	/* output:
	 *	3 3
	 *	2 2
	 *	1 1
	 *	2 2
	 *	0 0
	 */

	return 0;
}

