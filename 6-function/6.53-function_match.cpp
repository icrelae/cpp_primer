/* 2016.10.16 15:57
 * P_220
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// a
int calc(int &, int &);
int calc(const int &, const int &);
// b
int calc(char *, char *);
int calc(const char *, const char *);
// c: invalid, redefinition
int calc(char *, char *);
int calc(char * const, char * const);


int main(int argc, char **argv)
{

	return 0;
}

