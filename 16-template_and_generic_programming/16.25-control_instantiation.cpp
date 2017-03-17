/* 2017.03.17 08:33
 * P_599
 * !!!
 * control instantiation: !!!
 *	explicit instantiation: to avoid multi-instantiation
 *		extern template declaration;	// declaration
 *		template declaration;		// definition
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Application.cc
// 'Blob<string>' and 'compare(int, int)' will be instantiated in somewhere else;
// compiler will instantiate a template when using it,
// so 'extern' declaration have to be placed before any using of it !!!
extern template class Blob<string>;
extern template int compare(const int&, const int&);
Blob<string> sa;
int i = compare(a[0], a[2]);
// here will instantiate 'Blob<int>(initializer_list)'
Blob<int> a = {0, 1, 2, 3, 4};

// templateBuild.cc
// here's definition will instantiate every member of 'Blob<string>' [even some
// one never be used] and 'compare(int, int)'
template class Blob<string>;
template int compare(const int&, const int&);

extern template class vector<string>;	// declaration
template class vector<Sales_data>;	// definition

int main(int argc, char **argv)
{

	return 0;
}

