/* 2017.01.08 10:38
 * P_449
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class numbered {
	public:
		numbered() { mysn = ++i;}
		numbered(numbered const &n) { mysn = ++i;}
		int mysn;
	private:
		 static int i;
};
int numbered::i = 0;

void f1(numbered s)
{
	cout << s.mysn << ' ';
}
void f2(numbered const &s)
{
	cout << s.mysn << ' ';
}

int main(int argc, char **argv)
{
	numbered a, b = a, c = b;
	f1(a); f1(b); f1(c); cout << endl;
	f2(a); f2(b); f2(c); cout << endl;
	/* output:
	 *	4 5 6 
	 *	1 2 3 
	 */

	return 0;
}

