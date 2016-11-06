/* 2016.10.16 14:13
 * P_213
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string make_plural(size_t ctr, 
		const string &word, const string &ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

int main(int argc, char **argv)
{
	cout << make_plural(1, "success") << endl;
	cout << make_plural(2, "success") << endl;
	cout << make_plural(1, "failure") << endl;
	cout << make_plural(2, "failure") << endl;

	return 0;
}

