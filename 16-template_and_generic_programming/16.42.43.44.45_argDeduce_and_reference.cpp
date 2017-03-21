/* 2017.03.21 09:35
 * P_610
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

using namespace std;

template<typename T> void f1(T&);
template<typename T> void f2(const T&);
// deduce type by lvalue argument !!!
void DeduceTypeByLvalArgEG()
{
	int i = 0;
	const int ci = 1;
	f1(i);		// T: int
	f1(ci);		// T: const int
	//f1(3);	// invalid, arg have to be lvalue
	f2(i);		// T: int
	f2(ci);		// T: int
	f2(3);		// T: int, 'const &' can be bond by rvalue
}
/* reference collapsing !!!
 * 1. passing lval to a rval-reference parameter, 'T' will be deduced to be
 * lval of arg
 * 2. all 'reference of a reference' will collapsing to a common lval-reference
 * except in one case 'T&& &&', therefore:
 *	'T& &', 'T& &&', 'T&& &' will collapsing to 'T&'
 *	'T&& &&' will collapsing to 'T&&'
 */
template<typename T> void rc(T &&arg)
{
	T t = arg;
	++t;
	if (arg == t);	// uncertain
	// resolution:
	typename remove_reference<T>::type t2;
}
void ReferenceCollapsingEG()
{
	int i = 1;	// i: lvalue, 'int &'
	rc(i);		// T: 'int &'; arg: 'int &'; t: 'int &'
	rc(2);		// T: 'int'; arg: 'int &&'; t: 'int'
}

template<typename T> void g42(T&& val);
template<typename T> void g44a(T val);
template<typename T> void g44b(const T& val);
template<typename T> void g45(T&& val)
{
	vector<T> v;
}

int main(int argc, char **argv)
{
	int i = 0;
	const int ci = i;

	g42(i);		// T: 'int &'; val: 'int &'
	g42(ci);	// T: 'const int &'; val: 'const int &'
	g42(i * ci);	// T: 'int &'; val: 'int &&'

	g42(i = ci);	// T: 'int &'

	g44a(i);	// T: 'int'; val: 'int'
	g44a(ci);	// T: 'int'; val: 'int'
	g44a(i * ci);	// T: 'int'; val: 'int'

	g44b(i);	// T: 'int'; val: 'int'
	g44b(ci);	// T: 'int'; val: 'int'
	g44b(i * ci);	// T: 'int&&'; val: 'int &'

	g45(42);	// T: 'int'; v: 'vector<int>'
	g45(i);		// T: 'int &'; v: 'vector<int &>'

	return 0;
}

