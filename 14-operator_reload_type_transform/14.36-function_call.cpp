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
			string str("");
			if (is >> str)
				vecStr.push_back(str);
			return str;
		}
		void ShowVec()
		{
			for (auto str : vecStr)
				cout << str << endl;
		}
	private:
		vector<string> vecStr;
};

int main(int argc, char **argv)
{
	Foo foo;
	cout << foo(cin) << '#' << endl;
	cout << foo(cin) << '#' << endl;
	cout << foo(cin) << '#' << endl;
	foo.ShowVec();

	return 0;
}

