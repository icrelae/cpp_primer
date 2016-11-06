/* 2016.10.25 22:46
 * P_235
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

istream& read(istream &in, string &data)
{
	in >> data;
	return in;
}

int main(int argc, char **argv)
{
	string data1, data2;
	if (read(read(cin, data1), data2))
		cout << data1 << ' ' << data2 << endl;
	else
		cout << "error" << endl;

	return 0;
}
/* input:	<c-d>
 * output:	error
 * input:	123<c-d>
 * output:	error
 * input:	123 asd
 * output:	123 asd
 */

