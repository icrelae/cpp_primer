/* 2017.04.13 09:31
 * P_708
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace A {
	class C {
		// here two fiend-func no delaration out of 'C'
		// they are declared as member of 'A' implicitly
		friend void f2();
		friend void f(const C&);
	};
}
void ScopeEG()
{
	A::C cobj;
	f(cobj);	// have an arg, can be searched by implicit declaration in 'A'
	//f2();		// have no arg, cannot be searched
}

template<typename T>
void swap(T v1, T v2)
{
	using std::swap;
	swap(v1, v2);	// override 'swap()' in upper layer, usign 'std::swap()'

	std::swap(v1, v2);
}

int main(int argc, char **argv)
{

	return 0;
}

