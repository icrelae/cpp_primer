/* 2017.04.22 17:57
 * P_761
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a, val;
void foo(int val)
{
	static int si;
	enum Loc { a = 1024, b};
	// local class can access only typeName, static-variable and enum
	// members in outmost scope
	struct Bar {
		Loc locVal;
		int barVal;
		void fooBar(Loc l = a) {
			//barVal = val;		// invalid
			barVal = ::val;
			barVal = si;
			locVal = b;
		}
	};
}
////////////////////////////////////////////////////////////

/* nonportable features:
 * bit-field
 * volatile
 * extern "C" { }
 */
class Bitfield {
	unsigned a: 2;
	unsigned b: 2;
	unsigned c: 2;
	// better using 'unsigned' for bit-field, behaviors will depend on
	// implementation if using 'signed'
	// '&' is unavailable for bit-field, no pointer can point to bit-field
};

void Volatile()
{
	volatile int v;
	//int *ip = &v;		// invalid
	volatile int *vip = &v;	// valid
	int* volatile ivp;
	volatile int* volatile vivp;
	// synthetic copy|move constructor and assignment-operator are
	// unavailable for volatile objs
}

// externC effect not only 'f1', but also 'void(*)(int)', means func-pointer
// passing into 'f1' have to be C-func
extern "C" void f1(void(*)(int));
// passing C-func pointer into C++ function
extern "C" typedef void (FC)(int);
void f2(FC *);
// macro for file be compiled under both C and C++
#ifdef __cplusplus
extern "C" {
#endif
	void Foo();
#ifdef __cplusplus
}
#endif

// invalid, C not support overload, if one 'compute' is externC, the others
// have to be C++
extern "C" int compute(int*, int);
//extern "C" double compute(double*, int);
double compute(double*, int);

int main(int argc, char **argv)
{

	return 0;
}

