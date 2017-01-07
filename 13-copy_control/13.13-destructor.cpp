/* 2017.01.07 21:01
 * P_447
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class X {
	public:
		X() { cout << "X()" << endl;}
		X(X const &x) { cout << "X(X const &)" << endl;}
		X & operator =(X const &x)
		{
			cout << "operator =" << endl;
			return *this;
		}
		~X() { cout << "~X()" << endl;}
};

void Foo1(X x) {}
void Foo2(X &x) {}
void Foo3()
{
	X *px = new X;
	delete px;
}
void Foo4()
{
	vector<X> vecX{X(), X(), X()};
}

int main(int argc, char **argv)
{
	X x;
	cout << "Foo1()" << endl;
	Foo1(x);
	cout << "Foo2()" << endl;
	Foo2(x);
	cout << "Foo3()" << endl;
	Foo3();
	cout << "Foo4()" << endl;
	Foo4();
	cout << "the end" << endl;
	/* outpu:
	 * X()
	 * Foo1()
	 * X(X const &)
	 * ~X()
	 * Foo2()
	 * Foo3()
	 * X()
	 * ~X()
	 * Foo4()
	 * X()
	 * X()
	 * X()
	 * X(X const &)
	 * X(X const &)
	 * X(X const &)
	 * ~X()
	 * ~X()
	 * ~X()
	 * ~X()
	 * ~X()
	 * ~X()
	 * the end
	 * ~X()
	 */

	return 0;
}

