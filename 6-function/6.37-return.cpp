/* 2016.10.16 11:29
 * P_206
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string (&Foo())[10];

typedef string (&Str10)[10];
Str10 Foo1();

auto Foo2() -> string (&)[10];

string str[10];
decltype(str) &Foo3();
int main(int argc, char **argv)
{

	return 0;
}
