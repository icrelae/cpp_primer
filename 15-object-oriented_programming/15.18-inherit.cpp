/* 2017.02.19 21:24
 * P_546
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
struct Pub_Derv: public Base {
	int f() const { return prot_mem;}
	//char g() { return priv_mem;} //can't access private member
};
struct Prot_Derv: protected Base {
	int f() const { return prot_mem;}
};
struct Priv_Derv: private Base {
	int f() const { return prot_mem;}
};
struct Derived_from_Public: public Pub_Derv {
	// prot_mem is protected in Pub_Derv
	int use_base() { return prot_mem;}
};
struct Derived_from_Protected: protected Prot_Derv {
	// prot_mem is protected in Priv_Derv
	int use_base() { return prot_mem;}
};
struct Derived_from_Private: public Priv_Derv {
	// prot_mem is private in Priv_Derv
	//int use_base() { return prot_mem;}
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

