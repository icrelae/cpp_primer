/* 2016.10.16 12:26
 * P_210
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// a: redefinition, can't tell top-level const
void calc(int a)
{
	cout << "not const" << endl;
}
void calc(int const a)
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
void lookup(int *);
void lookup(int * const);
// valid
void lookup(int &);
void lookup(const int &);
void lookup(int *);
void lookup(const int *);
int main(int argc, char **argv)
{

	return 0;
}

