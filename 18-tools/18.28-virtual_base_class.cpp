/* 2017.04.16 14:00
 * P_719
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Base {
	void bar(int) {
		cout << "bar in Base()" << endl;
	}
	int ival = 0;
};
struct Derived1: virtual public Base {
	void bar(char) {
		cout << "bar in Derived1()" << endl;
	}
	void foo(char) {
		cout << "foo in Derived1()" << endl;
	}
	char cval = 'a';
};
struct Derived2: virtual public Base {
	void foo(int) {
		cout << "foo in Derived2()" << endl;
	}
	int ival = 2;
	char cval = 'b';
};
class VMI: public Derived1, public Derived2 {
	public:
		void asdf() {
			bar('a');	// Derived1::bar()
			bar(10);	// Derived1::bar() !!!
			Derived1::foo('a');
			Derived2::foo(10);
			cout << ival;	// Derived2::ival
			cout << Base::ival;
			cout << Derived1::cval;
			cout << Derived2::cval;
		}
};

int main(int argc, char **argv)
{
	VMI vmi;
	vmi.asdf();
	/* output:
	 *	bar in Derived1()
	 *	bar in Derived1()
	 *	foo in Derived1()
	 *	foo in Derived2()
	 *	20ab
	 */

	return 0;
}

