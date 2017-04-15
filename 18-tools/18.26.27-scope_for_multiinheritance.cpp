/* 2017.04.15 21:00
 * P_717
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base1 {
	public:
		void print(int) const;
	protected:
		int ival;
		double dval;
		char cval;
	private:
		int *id;
};
class Base2 {
	public:
		void print(double) const;
	protected:
		double fval;
	private:
		double dval;
};
class Derived: public Base1 {
	public:
		void print(string) const;
	protected:
		string sval;
		double dval;
};
class MI: public Derived, public Base2 {
	public:
		/* here isn't overload !!!
		 * for 'print', only search name, never check arguments list
		 */
		void print(vector<double>) const;
		void print(int x) const {
			Base1::print(x);
		}
	protected:
		int *ival;
		vector<double> dvec;
		void foo(double cval) {
			int dval = Base1::dval + Derived::dval;
			Base2::fval = dvec[dvec.size()-1];
			Derived::sval[0] = Base1::cval;
		}
};

int main(int argc, char **argv)
{
	MI mi;
	mi.print(42);
	mi.Base1::print(42);

	return 0;
}

