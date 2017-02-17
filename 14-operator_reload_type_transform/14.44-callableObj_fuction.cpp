/* 2017.02.15 08:30
 * P_514
 * !!!
 * callable objs: !!!
 *		function
 *		function pointer
 *		lambda
 *		obj building by bind()
 *		class which overload 'operator()'
 * function: using to store all type of callable objs !!!
 * function<T> f;			// T: retType(args)
 *		function<T> f(nullptr);
 *		function<T> f(obj);		// copy callable obj
 * f	// using as a condition, when f have a callable obj return true, else false
 * function<T>::result_type
 * function<T>::argument_type
 * function<T>::first_argument_type
 * function<T>::second_argument_type
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>

using namespace std;

int add(int i, int j) { return i + j;}
auto mod = [](int i, int j) {return i % j;};
struct divide {
	int operator() (int denominator, int divisor)
	{
		return denominator / divisor;
	}
};
void FunctionEG()
{
	map<string, function<int(int, int)>> binops = {
		{"+", add},
		{"-", std::minus<int>()},
		{"/", divide()},
		{"*", [](int i, int j) { return i * j;}},
		{"%", mod},
	};
	cout << binops["+"](1, 2) << ' ';
	cout << binops["-"](4, 1) << ' ';
	cout << binops["/"](6, 2) << ' ';
	cout << binops["*"](1, 3) << ' ';
	cout << binops["%"](7, 4) << ' ';
	cout << endl;
	// output: 3 3 3 3 3 
}

int OverloadTest(int, int) { return 0;}
int OverloadTest(double, double) { return 0;}
void FunctionEG1()
{
	map<string, function<int(int, int)>> mapTest;
	//mapTest["overloadTest"] = OverloadTest;	// wrong because of overload!!!
	// method 1
	int (*fp)(int, int) = OverloadTest;
	mapTest["overloadTest"] = fp;
	// method 2
	mapTest["overloadTest"] = [](int i, int j){ return OverloadTest(i, j);};
}

int main(int argc, char **argv)
{
	map<char, function<int(int, int)>> binops = {
		{'+', add},
		{'-', std::minus<int>()},
		{'/', divide()},
		{'*', [](int i, int j) { return i * j;}},
		{'%', mod},
	};

	int a, b;
	char op;
	while (cin >> a >> op >> b) {
		cout << binops[op](a, b) << endl;
	}

	return 0;
}

