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
	/* return ret.sorted();
	 *	call 'sorted() const&' recursively, loop infinitely
	 */
}

Foo ReturnRvalue()
{
	return Foo();
}
void ReferenceQualifierEG()
{
	Foo f1;
	ReturnRvalue().sorted();
	f1.sorted();
	/* output:
	 *	rvalue call this sorted
	 *	lvalue(const or not) call this sorted
	 */
}

int main(int argc, char **argv)
{
	ReferenceQualifierEG();

	return 0;
}

