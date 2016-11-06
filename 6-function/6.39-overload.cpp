/* 2016.10.16 12:26
 * P_210
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// a: redefinition
void calc(int a, int b)
{
	cout << "not const" << endl;
}
void calc(const int a, const int b)
{
	cout << "const" << endl;
}

// b: ambiguating declaration of get
int get();
double get();

// c
int *reset(int *);
double *reset(double *);

/* eg */
// invalid: overloaded function can't tell top-level const!!!
void lookup(int);
void lookup(const int);
// valid
void lookup(int &);
void lookup(const int &);
void lookup(int *);
void lookup(const int *);
int main(int argc, char **argv)
{

	return 0;
}

