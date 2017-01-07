/* 2017.01.07 21:01
 * P_443
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr {
	public:
		HasPtr(string const &s = string()):
			ps(new string(s)), i(0) { }
		HasPtr(HasPtr const &orig):
			ps(new string(*orig.ps)), i(orig.i) { }
	private:
		string *ps;
		int i;
};

int main(int argc, char **argv)
{

	return 0;
}

