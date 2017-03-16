/* 2017.03.16 08:47
 * P_595
 * !!!
 * 
 * using type-member of class: !!!
 *	compiler won't know 'Foo::size_type * p' is a multiple for static varriable or a definition for 'p' until instantiation; it take scope-operator like 'Foo::size_type' as a value rather than type; so if you'd like to using a type-member of a class template, you have to specify for compiler explicitly that it is a type by using key word 'typename';
 * default tmplate argument: !!!
 *	template<typename T, typename F = less<T>>
 *	for class template, if all args have default value, it also need an empty '<>'
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T, typename U, typename V> void f1(T, U, V);
template<typename T> T f2(int &);
template<typename T> inline  T foo(T, unsigned int*);
template<typename T> void f4(T, T);
// here's 'Ctype' will be override by 'typename Ctype' !!!
typedef char Ctype;
template<typename Ctype> Ctype f5(Ctype a);

int main(int argc, char **argv)
{

	return 0;
}

