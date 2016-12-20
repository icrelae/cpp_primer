/* 2016.12.20 21:37
 * P_357
 * bind(), ref(), cref(): !!!
 * head file: <functionl>
 * auto newCallable = bind(callable, arglist);
 * eg:	auto NewFunc = bind(FuncName, _1, 0, "a", _2);
 *	NewFunc(1, 2) equals to FuncName(1, 0, "a", 2);
 * namespace of _1 _2: std::placeholders
 *	must using it explicitly, otherwise "_1 was not declared"
 * ref(outstream): return reference of outstream
 * cref(outstream): return const reference of outstream
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

void ArgumentBindingEG()
{
	auto BindEG = [] (ostream &os, string const str1, int a, string const str2, int b) {
		os << str1 << ' ' << a << ' ';
		os << str2 << ' ' << b << ' ';
	};
	auto NewBindEG = bind(BindEG, ref(cout), "argA", 1, _1, _2);
	auto NewBindEG2 = bind(BindEG, ref(cout), "argA", _2, _1, 0);
	NewBindEG("_1", 2);
	NewBindEG2("_1", 2);
	// output: argA 1 _1 2
	// output: argA 2 _1 0 
}

bool CheckStrSize(string const &str, string::size_type const size)
{
	return str.size() > size;
}
vector<string>::size_type CountStrSizeGT6(vector<string> const &words)
{
	return count_if(words.begin(), words.end(), bind(CheckStrSize, _1, 5));
	auto CheckStrSizeGT5 = bind(CheckStrSize, _1, 5);
	return count_if(words.begin(), words.end(), CheckStrSizeGT5);
}

int main(int argc, char **argv)
{
	ArgumentBindingEG();

	vector<string> vecStr({
			"123",
			"1234",
			"12345",
			"123456",
			"1234567",
			});
	cout << CountStrSizeGT6(vecStr);	// output: 2

	return 0;
}

