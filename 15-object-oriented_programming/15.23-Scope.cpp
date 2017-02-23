/* 2017.02.23 21:16
 * P_551
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct FooBase {
	int mem;
	int memfcn() { return 0;}
	void olEg() { cout << " empty ";};
	void olEg(int) { cout << " int ";};
	void olEg(double) { cout << " double ";};
};
struct FooDerived: public FooBase {
	// hide Base::mem, but it still there !!!
	double mem;
	// function which declared in derived-class won't overload the same
	// name function which inherit from base-class !!!
	int memfcn(int) { return 1;}
	// either overload all of olEg(), or neither is overloaded, no matter
	// they are virtual or not !!!
	using FooBase::olEg;
	void olEg() { cout << " empty(derived) ";}
};
void ScopeForInheritEG()
{
	FooBase b;
	FooDerived d;
	b.memfcn();
	d.memfcn(10);
	//d.memfcn();	// illegal
	d.FooBase::memfcn();

	d.olEg();
	d.olEg(1);
	d.olEg(1.1);
	// output: empty(derived)  int  double 
}

struct Base {
	virtual int fcn();
};
struct D1: public Base {
	int fcn();
	virtual void f2();
};

int main(int argc, char **argv)
{
	ScopeForInheritEG();

	return 0;
}

