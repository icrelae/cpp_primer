/* 2017.04.18 21:55
 * P_731
 * !!!
 * RTTI: run-time type identification: !!!
 * dynamic_cast<T>(e):
 *	type of 'e' have to be one of:
 *		public derived of type
 *		public base of type
 *		type of 'T'
 * dynamic_cast<type*>(e):
 *	'e' have to be a valid pointer
 *	'e=0' if failed
 * dynamic_cast<type&>(e):
 *	'e' have to be a lval
 *	throw 'bad_cast' if failed
 * dynamic_cast<type&&>(e):
 *	'e' have to be a rval
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class A {
	public:
		A() { }
		virtual ~A() { }
};
class B: public A {
	public:
		B() { }
		virtual ~B() { }
};
class C: public B {
	public:
		C() { }
		virtual ~C() { }
};
class D: public B, public A {
	public:
		D() { }
		virtual ~D() { }
};
void Ex3()
{
	A *pa; B *pb; C *pc;
	pa = new C;
	pb = dynamic_cast<B*>(pa);
	pb = new B;
	pc = dynamic_cast<C*>(pb);
	//pa = new D;			// invalid
	pb = dynamic_cast<B*>(pa);
}
void Ex4()
{
	A *pa = new C;
	if (C *pc = dynamic_cast<C*>(pa)) {
		C &rc = dynamic_cast<C&>(*pc);
	} else {
		A &ra = dynamic_cast<A&>(*pa);
	}
}

int main(int argc, char **argv)
{
	Ex3();

	return 0;
}

