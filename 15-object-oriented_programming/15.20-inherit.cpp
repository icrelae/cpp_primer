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
	int f() const { return prot_mem;}
	//char g() { return priv_mem;} //can't access private member
	void memfcn(Base &b) { b = *this;}
};
struct Prot_Derv: protected Base {
	int f() const { return prot_mem;}
	void memfcn(Base &b) { b = *this;}
};
struct Priv_Derv: private Base {
	int f() const { return prot_mem;}
	void memfcn(Base &b) { b = *this;}
};
/* member functions and friends of classes derived from D may use the
 * devived-tobase conversion if D inherits from B either public or protected !!!
 */
struct Derived_from_Public: public Pub_Derv {
	// prot_mem is protected in Pub_Derv
	int use_base() { return prot_mem;}
	void memfcn(Base &b) { b = *this;}
};
struct Derived_from_Protected: public Prot_Derv {
	// prot_mem is protected in Priv_Derv
	int use_base() { return prot_mem;}
	void memfcn(Base &b) { b = *this;}
};
struct Derived_from_Private: public Priv_Derv {
	// illegalprot_mem is private in Priv_Derv
	//int use_base() { return prot_mem;}
	// illegal
	//void memfcn(Base &b) { b = *this;}
};

int main(int argc, char **argv)
{
	struct Pub_Derv d1;
	struct Priv_Derv d2;
	struct Prot_Derv d3;
	struct Derived_from_Public dd1;
	struct Derived_from_Protected dd2;
	struct Derived_from_Private dd3;
	Base *p = &d1;
	// derived-to-base conversion can be used only if D inherits from B publicly !!!
	//p = &d2;
	//p = &d3;
	p = &dd1;
	//p = &dd2;
	//p = &dd3;

	return 0;
}

