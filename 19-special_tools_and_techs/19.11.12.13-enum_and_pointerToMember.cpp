/* 2017.04.21 09:00
 * P_741
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// scoped unscoped and anonymous enum !!!
// scoped enumeration
enum class E1 {
	input = 0,
	output = 1,
	append = 2,
};
// unscoped enumeration, can be anonymous or not
//enum anonymousEnum {
enum {
	input = 0,
	output = 1,
	append = 2,
} anoE1, anoE2;
enum duplicate {
	//input,	// invalid, duplicate with unscoped enum 'input' before
};
void EnumEG()
{
	//E1 e1 = input;	// cannot convert 'anonymous_enum' into 'E1'
	//E1 e3 = 2;		// cannot convert 'int' into 'E1'
	E1 e2 = E1::input;
	int i1 = output;	// 'anonymous_enum' can be auto-converted into 'int' implicitly
	//int i2 = E1::output;	// named enum cannot convert implicitly
}

// forward-declaration !!!
enum intValues: unsigned long;	// for anonymous-enum, must specify type
enum class open_modes;

// argument match with enum !!!
enum Tokens {
	INLINE = 12,
	VIRTUAL = 129,
};
void Foo(Tokens)
{
	cout << "in Foo(Tokens)" << endl;
}
void Foo(int)
{
	cout << "in Foo(int)" << endl;
}
void Foo1(int)
{
	cout << "in Foo2(int)" << endl;
}
void EnumEG1()
{
	Tokens curTok = INLINE;
	Foo(128);
	Foo(curTok);
	Foo(INLINE);	// accurately match 'Foo(Tokens)'
	Foo1(INLINE);	// 'Token' can be promoted to 'int'
	/* output:
	 *	in Foo(int)
	 *	in Foo(Tokens)
	 *	in Foo(Tokens)
	 *	in Foo2(int)
	 */
}
//////////////////////////////////////////////////////////////

class Foo;
class Screen {
	public:
		typedef string::size_type pos;
		Screen(pos c, pos h, pos w): cursor(c), height(h), width(w) { }
		char get_cursor() const {
			return contents[cursor];
		}
		char get() const;
		char get(pos ht, pos wd) const;
		string contents;
		pos cursor;
		pos height, width;
};
class Sales_data {
	public:
		Sales_data(const string &s): isbn(s) { }
		string isbn;
};

int main(int argc, char **argv)
{
	// 'const *cp' can point to both const or non-const 'Screen'
	const string::size_type Screen::*cp = &Screen::cursor;
	Screen sc(3, 3, 3);
	cout << sc.*cp << endl;

	string Sales_data::*bnp = &Sales_data::isbn;
	Sales_data book("asdf");
	cout << book.*bnp << endl;
	// output: 3 asdf

	return 0;
}

