/* 2017.03.17 08:33
 * P_599
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T> class Stack { };
void f1(Stack<char>);				// no instantiation
class Exercise {
	Stack<double> &rsd;			// no instantiation
	Stack<int> si;				// instatiate Stack<int>
};

int main(int argc, char **argv)
{
	Stack<char> *sc;			// no instantiation
	f1(*sc);				// instantiate Stack<char>;
	int iObj = sizeof(Stack<string>);	// instantiate Stack<string>

	return 0;
}

