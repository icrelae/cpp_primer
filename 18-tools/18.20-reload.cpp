/* 2017.04.14 09:00
 * P_710
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace NS {
	class Quote { };
	void display(const Quote&) { }
	void print(int);
}
class Bulk_item: public NS:: Quote {
};
void SearchEG()
{
	Bulk_item bookl;
	display(bookl);
	/* base of Bulk_item is 'Quote', as a result, 
	 * candidate of 'display()' will be searched in not only
	 * namespace of 'Bulk_item', but also 'Quote'
	 */
}
//using NS::print(int);	// invalid, using declaration cannot specify arg list
using NS::print;

namespace primerLib {
	void compute();
	void compute(const void*);
}
//using primerLib::compute;
void vompute(int);
void compute(double, double = 3.4);
void compute(char*, char* = 0);
void f()
{
	// if putting 'using' out of 'f()', 'compute(0)' will be ambiguous with
	// 'compute(double)', 'copute(char*)' and 'compute(void*)';
	// if putting innerly, there is only one 'copute(void*)' in the scope in 'f()'
	using primerLib::compute;
	compute(0);
}

int main(int argc, char **argv)
{

	return 0;
}

