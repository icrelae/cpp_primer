/* 2016.08.28 16:08
 * decltype(expr):
 * 1.infer type of expr by compiler when compileing, never calculate expr realy.
 * 2.when expr is like "(xxx)" means decltype((xxx)), the type will always be
 * an alias because (xxx) will be treated as an expression of a variable that
 * returns an alias, but xxx will be treated as a value.
 */
#include <iostream>

unsigned int Foo()
{
	static int x = 0;
	std::cout << ++ x;
}

int main(int argc, char **argv)
{
	int i = 42, *p = &i, &r = i;
	auto a = p;		// int *a;
	decltype(r + 0) b;	// int b;
	//decltype(*p) c;	// int &c;
	decltype(Foo) d;	// unsigned int d;
	//decltype((Foo)) e;	// unsigned int &e;
	Foo();			// output: 1


	return 0;
}

