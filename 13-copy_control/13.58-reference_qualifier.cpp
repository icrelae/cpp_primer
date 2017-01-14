/* 2017.01.14 12:23
 * P_485
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Foo {
	public:
		Foo() { }
		Foo(const Foo &f): data(f.data) { }
		Foo sorted() &&;
		Foo sorted() const &;
	private:
		vector<int> data;
};
Foo Foo::sorted() &&
{
	cout << "rvalue call this sorted" << endl;
	sort(data.begin(), data.end());
	return *this;
}
Foo Foo::sorted() const &
{
	cout << "lvalue(const or not) call this sorted" << endl;
	Foo ret(*this);
	sort(ret.data.begin(), ret.data.end());
	return ret;
	// output of ReferenceQualifierEG():
	//	rvalue call this sorted
	//	lvalue(const or not) call this sorted
}
/* 13.56
Foo Foo::sorted() const &
{
	cout << "lvalue(const or not) call this sorted" << endl;
	Foo ret(*this);
	return ret.sorted();
	// output of ReferenceQualifierEG():
	//	rvalue call this sorted
	//	lvalue(const or not) call this sorted
	//	rvalue call this sorted
}
*/
/* 13.57
Foo Foo::sorted() const &
{
	return Foo(*this).sorted();
	// output of ReferenceQualifierEG():
	//	lvalue(const or not) call this sorted * n
}
*/

Foo ReturnRvalue()
{
	return Foo();
}
void ReferenceQualifierEG()
{
	Foo f1;
	ReturnRvalue().sorted();
	f1.sorted();
}

int main(int argc, char **argv)
{
	ReferenceQualifierEG();

	return 0;
}

