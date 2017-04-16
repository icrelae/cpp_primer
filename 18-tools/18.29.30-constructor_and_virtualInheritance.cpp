/* 2017.04.16 14:49
 * P_721
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Class {
	public:
		Class() {
			cout << "construct Class" << endl;
		}
		~Class() {
			cout << "destruct Class" << endl;
		}
};
class Base: public Class {
	public:
		Base() {
			cout << "construct Base" << endl;
		}
		Base(const Base&);
		Base(int);
		~Base() {
			cout << "destruct Base" << endl;
		}
};
class D1: virtual public Base {
	public:
		D1() {
			cout << "construct D1" << endl;
		}
		D1(const D1 &d): Base(d) { }
		D1(int i): Base(i) { }
		~D1() {
			cout << "destruct D1" << endl;
		}
};
class D2: virtual public Base {
	public:
		D2() {
			cout << "construct D2" << endl;
		}
		D2(const D2 &d): Base(d) { }
		D2(int i): Base(i) { }
		~D2() {
			cout << "destruct D2" << endl;
		}
};
class MI: public D1, public D2 {
	public:
		MI() {
			cout << "construct MI" << endl;
		}
		MI(const MI &mi): D1(mi), D2(mi) { }
		MI(int i): D1(i), D2(i) { }
		~MI() {
			cout << "destruct MI" << endl;
		}
};
class Final: public MI, public Class {
	// direct base calss 'Class' inaccessible due to ambiguity
	public:
		Final() {
			cout << "construct Final" << endl;
		}
		Final(const Final &f): MI(f) { }
		Final(int i): MI(i) { }
		~Final() {
			cout << "destruct Final" << endl;
		}
};

int main(int argc, char **argv)
{
	/* a
	 * Class Base D1 D2 MI [Class] Final
	 */
	Final fin;
	/* output:
	 *	construct Class
	 *	construct Base
	 *	construct D1
	 *	construct D2
	 *	construct MI
	 *	construct Class
	 *	construct Final
	 */

	/* b
	 * 1 'Base', 2 'Class'
	 */

	/* c
	 */
	Base *pb;
	Class *pc;
	MI *pmi;
	D2 *pd2;
	//pb = new Class;	// 'Class*' to 'Base*'
	//pc = new Final;	// 'Class' is an ambiuous base of Final
	//pmi = pb;		// invalid conversion from 'MI*' to 'Base*'
	pd2 = pmi;


	return 0;
}

