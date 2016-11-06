/* 2016.10.13 23:45
 * P_196
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pirnt(const int ia[10])
{
	/* !!!
	 * ia degrade to 'const int *'
	 * any int array can passing to ia, such as 'int x[3]'
	 */
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << ' ';
}
void print1(const int (&ia)[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << ' ';
}
void print2(const int (*ia)[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << (*ia)[i] << ' ';
}
int main(int argc, char **argv)
{
	const int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	print1(a);
	print2(&a);

	return 0;
}

