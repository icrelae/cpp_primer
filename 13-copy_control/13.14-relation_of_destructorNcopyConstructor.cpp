/* 2017.01.08 10:38
 * P_448
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class numbered {
	public:
		numbered() { mysn = ++i;}
		int mysn;
	private:
		 static int i;
};
int numbered::i = 0;

void f(numbered s)
{
	cout << s.mysn << ' ';
}

int main(int argc, char **argv)
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	// output: 1 1 1 

	return 0;
}

