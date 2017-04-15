/* 2017.04.15 21:00
 * P_715
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base1 {
	public:
		virtual ~Base1() {
			cout << "destruct Base1" << endl;
		}
		virtual void print() {
			cout << "print of Base1" << endl;
		}
};
class Base2 {
	public:
		virtual ~Base2() {
			cout << "destruct Base2" << endl;
		}
		virtual void print() {
			cout << "print of Base2" << endl;
		}
};
class D1: public Base1 {
	public:
		virtual ~D1() {
			cout << "destruct D1" << endl;
		}
		virtual void print() {
			cout << "print of D1" << endl;
		}
};
class D2: public Base2 {
	public:
		virtual ~D2() {
			cout << "destruct D2" << endl;
		}
		virtual void print() {
			cout << "print of D2" << endl;
		}
};
class MI: public D1, public D2 {
	public:
		virtual ~MI() {
			cout << "destruct MI" << endl;
		}
};

int main(int argc, char **argv)
{
	Base1 *pb1 = new MI;
	Base2 *pb2 = new MI;
	D1 *pd1 = new MI;
	D2 *pd2 = new MI;

	pb1->print();	// d1 print
	pd1->print();	// d1 print
	pd2->print();	// d2 print
	delete pb2;	// destruct: MI d2 b2 d1 b1
	delete pd1;	// destruct: MI d2 b2 d1 b1
	delete pd2;	// destruct: MI d2 b2 d1 b1
	/* output:
	 *	print of D1
	 *	print of D1
	 *	print of D2
	 *	destruct MI
	 *	destruct D2
	 *	destruct Base2
	 *	destruct D1
	 *	destruct Base1
	 *	destruct MI
	 *	destruct D2
	 *	destruct Base2
	 *	destruct D1
	 *	destruct Base1
	 *	destruct MI
	 *	destruct D2
	 *	destruct Base2
	 *	destruct D1
	 *	destruct Base1
	 */

	return 0;
}

