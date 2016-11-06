/* 2016.10.04 22:49
 * P_184
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

double _absolute(double d)
{
	return (d < 0 ? -d : d);
}

int main(int argc, char **argv)
{
	cout << _absolute(100) << endl;
	cout << _absolute(0) << endl;
	cout << _absolute(-100) << endl;

	return 0;
}

