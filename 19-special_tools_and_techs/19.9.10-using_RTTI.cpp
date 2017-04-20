/* 2017.04.20 08:42
 * P_736
 * !!!
 * type_info: header <typeinfo> !!!
 * returned class of 'typeid'
 *	no default constructor
 *	copy, assignment, move-constructor are deleted
 *	the only way to build a 'type_info' obj is using 'typeid'
 *	t1 == t2
 *	t1 != t2
 *	t.name()	// return cstr of type
 *	t1.before(t2)	// return bool stand for whether 't1' before 't2'
 */
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Base { };
class Derived: public Base { };
void Ex9()
{
	int arr[10];
	Derived d;
	Base *p = &d;
	cout << typeid(42).name() << ' '
		<< typeid(arr).name() << ' '
		<< typeid(std::string).name() << ' '
		<< typeid(p).name() << ' '
		<< typeid(*p).name() << endl;
	// output: i A10_i NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE P4Base 4Base
}

class A {
	virtual void Foo() { }
};
class B: public A {
	virtual void Foo() { }
};
class C: public B {
	virtual void Foo() { }
};
void Ex10()
{
	A *pa = new C;
	cout << typeid(pa).name() << ' ';	// A*
	C cobj;
	A& ra = cobj;
	cout << typeid(&ra).name() << ' ';	// A*
	B *px = new B;
	A& ra1 = *px;
	cout << typeid(ra1).name() << endl;	// B
	// output: P1A P1A 1B
}

int main(int argc, char **argv)
{
	Ex10();

	return 0;
}

