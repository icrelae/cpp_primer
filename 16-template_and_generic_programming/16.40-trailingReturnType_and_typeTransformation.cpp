/* 2017.03.19 13:18
 * P_607
 * !!!
 * type transformation template: header: <type_traits> !!!
 *	remove_reference<T>
 *		T: X&|X&&		Mod<T>::type == X
 *		else			Mod<T>::type == T
 *	add_const<T>
 *		T: X&|constX|function	Mod<T>::type == T
 *		else			Mod<T>::type == const T
 *	add_lvalue_reference<T>
 *		T: X&			Mod<T>::type == T
 *		T: X&&			Mod<T>::type == X&
 *		else			Mod<T>::type == T&
 *	add_rvalue_reference<T>
 *		T: X&|X&&		Mod<T>::type == T
 *		else			Mod<T>::type == T&&
 *	remove_pointer<T>
 *		T: X*			Mod<T>::type == X
 *		else			Mod<T>::type == T
 *	add_pointer<T>
 *		T: X&|X&&		Mod<T>::type == X*
 *		else			Mod<T>::type == T*
 *	make_signed<T>
 *		T: unsigned X		Mod<T>::type == X
 *		else			Mod<T>::type == T
 *	make_unsigned<T>
 *		T: signed X		Mod<T>::type == X
 *		else			Mod<T>::type == T
 *	remove_extend<T>
 *		T: X[n]			Mod<T>::type == X
 *		else			Mod<T>::type == T
 *	remove_all_extents<T>
 *		T: X[n1][n2]		Mod<T>::type == X
 *		else			Mod<T>::type == T
 *	
 */
#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

using namespace std;

template<typename It>
// return reference '(*it)&'
// wrong
//*It fcn(It beg, It end) { }
// right
auto fcn(It beg, It end) -> decltype(*beg) { }

template<typename It>
// return value '(*it)'
auto fcn2(It beg, It end) ->
	typename remove_reference<decltype(*beg)>::type { }

template<typename It>
//only type that support '+' can be passed
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
	return *beg;
}
int main(int argc, char **argv)
{

	return 0;
}

