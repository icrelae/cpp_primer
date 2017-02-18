/* 2017.02.18 08:32
 * P_540
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class base {
	public:
		string name() { return basename;}
		virtual void print(ostream &os) { os << basename;}
	private:
		string basename;
};
class derived: public base {
	public:
		void print(ostream &os) {
			base::print(os);
			os << " " << i;
		}
	private:
		int i;
};

int main(int argc, char **argv)
{
	base bobj, *bp1 = &bobj, &br1 = bobj;
	derived dobj;
	base *bp2 = &dobj, &br2 = dobj;
	// a: base::print()
	bobj.print(cout);
	// b: derived::print()
	dobj.print(cout);
	// c: derived::name()
	bp1->name();
	// d: base::name()
	bp2->name();
	// e: base::name()
	br1.print(cout);
	// f: derived::print()
	br2.print(cout);

	return 0;
}

