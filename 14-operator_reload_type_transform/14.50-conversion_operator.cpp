/* 2017.02.15 22:02
 * P_521
 * ambiguity !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1
struct A;
struct B {
	operator A() const;
};
struct A {
	A(B &) { }
};
void Foo(A) { }

// 2
struct C {
	operator int() const;
	operator double() const;
};

// 3
struct D {
	D(int);
};
struct E {
	E(int);
};
void Foo3(D) { }
void Foo3(E) { }
void AmbiguityEG()
{
	// 1
	B b;
	Foo(b);	// Foo(B::operator A()) or Foo(A::A(B &))

	// 2
	C c;
	long double = c;	// C::operator int() or C::operator double()

	// 3
	Foo3(10);
}

struct LongDouble {
	LongDouble (double = 0.0);
	operator double();
	operator float();
};
int main(int argc, char **argv)
{
	LongDouble ldObj;
	int ex1 = ldObj;	// ambiguous
	float ex2 = ldObj;

	return 0;
}

