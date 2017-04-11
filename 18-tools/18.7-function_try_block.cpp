/* 2017.04.11 08:55
 * P_690
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Foo {
	public:
		Foo();
	private:
		int data;
};
/* function try block !!!
 * the only method can deal with exception from initialization-list
 */
Foo::Foo() try: data(3)
{
} catch (exception) {
}

int main(int argc, char **argv)
{

	return 0;
}

