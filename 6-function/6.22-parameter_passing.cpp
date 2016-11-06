/* 2016.10.13 23:02
 * P_196
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Swap(int **a, int **b)
{
	int *tmp = *b;
	*b = *a;
	*a = tmp;
}
int main(int argc, char **argv)
{
	int a = 1, b = 2;
	int *pa = &a, *pb = &b;
	cout << *pa << ' ' << *pb << endl;
	Swap(&pa, &pb);
	cout << *pa << ' ' << *pb << endl;

	return 0;
}

