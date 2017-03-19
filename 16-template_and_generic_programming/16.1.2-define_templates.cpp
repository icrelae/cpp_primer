/* 2017.03.12 20:53
 * P_583
 * !!!
 * 
 * in order to instantiate a template, compiler have to know the defination of
 * whole template function; so it's different from class, the defination of
 * template function or member template function always be sited in headers;
 */
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

template<unsigned N, unsigned M>
// site 'inline' or 'constexpr' before return type !!!
inline int compare(const char (&p1)[N], const char (&p2)[M])
{
	cout << N << ' ' << M << endl;
	return strcmp(p1, p2);
}
void TemplateEG()
{
	char cstrA[] = "hi";
	char cstrB[] = "mom";
	// invalid according to book, but it is valid
	cout << compare(cstrA, cstrB) << endl;
	cout << compare("hi", "mom") << endl;
	/* output:
	 *	3 4
	 *	-5
	 *	3 4
	 *	-5
	 */
}

int main(int argc, char **argv)
{
	TemplateEG();

	return 0;
}

