/* 2017.03.18 16:01
 * P_603
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T> void f1(T, T);
template<typename T1, typename T2> void f2(T1, T2);

int main(int argc, char **argv)
{
	int i = 0, j = 42, *p1 = &i, *p2 = &j;
	const int *cp1 = &i, *cp2 = &j;

	f1(p1, p2);
	f2(p1, p2);
	f1(cp1, cp2);	// valid, passing value, irrelevant with 'const'
	f2(cp1, cp2);	// valid, passing value, irrelevant with 'const'
	f1(p1, cp1);	// invalid
	f2(p1, cp1);

	return 0;
}

