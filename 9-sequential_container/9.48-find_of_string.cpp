/* 2016.11.27 12:50
 * P_327
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	string numbers("0123456789"), name("r2d2");
	if (numbers.find(name) == string::npos)
		cout << "yes, string::npos";
	else
		cout << "no";

	return 0;
}

