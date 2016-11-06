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

	return 0;
}

