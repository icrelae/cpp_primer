/* 2017.02.19 21:24
 * P_547
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Foo1 {
	protected:
		int x;
};
class Foo2: protected Foo1  {
	public:
		using Foo1::x;	// become public !!!
};

class Base {
	public:
		void pub_mem();
	protected:
		int prot_mem;
	private:
		char priv_mem;
};
/* member functions and friends of D can use the conversion to B regardless of
 * how D inherits from B; the derived-to-base conversion to a direct base class
 * is always available to member and friends of a derived class !!!
 */
struct Pub_Derv: public Base {
	void memfcn(Base &b) { b = *this;}
};
struct Prot_Derv: protected Base {
	void memfcn(Base &b) { b = *this;}
};
struct Priv_Derv: private Base {
	void memfcn(Base &b) { b = *this;}
};
/* member functions and friends of classes derived from D may use the
 * devived-tobase conversion if D inherits from B either public or protected !!!
 */
struct Derived_from_Public: public Pub_Derv {
	void memfcn(Base &b) { b = *this;}
};
struct Derived_from_Protected: public Prot_Derv {
	void memfcn(Base &b) { b = *this;}
};
struct Derived_from_Private: public Priv_Derv {
	// illegal
	//void memfcn(Base &b) { b = *this;}
};

int main(int argc, char **argv)
{

	return 0;
}

