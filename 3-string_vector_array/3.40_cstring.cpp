/* 2016.09.18 22:58
 * P_110
 * joint to cstring
 */
#include <iostream>
#include <cstring>

char *Catenate(char *stra, char *strb)
{
	char *catResult = new char[strlen(stra) + strlen(strb) + 2];
	if (catResult != NULL) {
		strcpy(catResult, stra);
		strcat(catResult, " ");
		strcat(catResult, strb);
	}
	return catResult;
}
int main(int argc, char **argv)
{
	char a[] = "abcdefg";
	char b[] = "123456";
	char *p = Catenate(a, b);
	std::cout << p;
	delete []p;

	return 0;
}

