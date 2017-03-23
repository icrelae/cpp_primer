/* 2017.03.23 09:13
 * P_621
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
class Foo { };

int main(int argc, char **argv)
{
	print(cout, 1);
	print(cout, 2, 3, 4.5);
	print(cout, 5, 6, 7.8, "999");
	// output: 1 2 3 4.5 5 6 7.8 999 

	Foo foo;
	//print(cout, foo);	// invalid, no match '<<' for Foo

	return 0;
}

