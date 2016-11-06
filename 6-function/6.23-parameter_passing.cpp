/* 2016.10.13 23:02
 * P_196
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void DisplayArray(const int *pBeg, const int * const pEnd)
{
	while (pBeg != pEnd)
		cout << *pBeg ++ << ' ';
}
int main(int argc, char **argv)
{
	int i = 123, j[2] = {1234, 12345};

	DisplayArray(&i, &i+1);
	DisplayArray(j, &j[2]);

	return 0;
}

