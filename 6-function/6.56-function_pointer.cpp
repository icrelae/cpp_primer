/* 2016.10.16 16:10
 * P_224
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Add(int a, int b)
{
	return a + b;
}
int Subtract(int a, int b)
{
	return a - b;
}
int Multiply(int a, int b)
{
	return a * b;
}
int Divide(int a, int b)
{
	return a / b;
}
vector<int (*)(int, int)> vec = {Add, Subtract, Multiply, Divide};

int main(int argc, char **argv)
{
	int a = 2, b = 3;
	for (auto it : vec)
		cout << it(a, b) << ' ';

	return 0;
}
/* output:
 * 5 -1 6 0 
 */
