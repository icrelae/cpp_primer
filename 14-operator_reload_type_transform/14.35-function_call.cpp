/* 2017.02.09 22:14
 * P_507
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Foo {
	public:
		string operator()(istream &is)
		{
			string str;
			if (!(is >> str))
				str = "";
			return str;
		}
};

int main(int argc, char **argv)
{
	Foo foo;
	cout << foo(cin) << '#' << endl;

	return 0;
}

