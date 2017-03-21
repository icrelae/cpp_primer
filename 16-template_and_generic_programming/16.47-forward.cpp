/* 2017.03.21 20:11
 * P_614
 * !!!
 * std::forward<T>(arg): header: <utility> !!!
 *	return 'T &&arg'
 *	better not using 'using std::forward' as 'std::move', see 18.2.3-P_706
 */
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

template<typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
	f(t2, t1);
}
void f(int v1, int &v2) { cout << v1 << ' ' << ++v2 << endl;}
/* using 'T&&' keep attribute 'const' and '&|&&' !!!
 * flip1(f, i, j) will lose the attribute of '&|&&', 'int &v2' won't be changed;
 * attribuit 'const' and '&|&&' of args will be kept if param's type is
 * rval-reference like 'T&&', as 'flip2()';
 */
template<typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2)
{
	f(t2, t1);
}
void g(int &&i, int &j) { cout << i << ' ' << j << endl;}
/* using 'forward<>()' get original type of variable !!!
 * '&&' can keep attribute in 'T1' and 'T2', but as a variable, 't1' and 't2'
 * will always be a lval;
 * therefore 'flip2(g, i, 42)' will attempt to bind '(int&&)&&t2' of 'flip2()' to 'int
 * &&i' of 'g()';
 * to get '(int&&)t2' need to using 'std::forward<>()'
 */
template<typename F, typename T1, typename T2>
void flip3(F f, T1 &&t1, T2 &&t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main(int argc, char **argv)
{
	int i, j;
	flip1(f, i, j);		// error, j won't be changed
	flip2(f, i, j);		// right
	//flip2(g, i, 42);	// invalid, bind 'int&' to 'int&&'
	flip3(g, i, 42);	// right
	/* !!!
	 * here passing 'i' to 'T1 &&t1', 'T1' is 'int &',
	 * passing '42' to 'T2 &&t2', 'T2' is 'int &&'
	 * 'std::forward<T1>(t1)' is '(int& &&)t1' collapsing to '(int&)t1'
	 * 'std::forward<T2>(t2)' is '(int&& &&)t2' collapsing to '(int&&)t2'
	 */

	return 0;
}

