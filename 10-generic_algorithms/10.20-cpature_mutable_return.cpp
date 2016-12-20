/* 2016.12.19 20:54
 * P_354
 * !!!
 * ???
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void CaptureNReturnEG()
{
	int i = 42;
	// value passing when construct a lambda, not call it
	auto lmd = [i] { cout << i << endl;};
	i = 0;
	lmd();			// output: 42

	int j = 42;
	// passing reference
	auto lmd2 = [&j] { cout << ++j << endl; return j;};
	int a = lmd2();		// output: 43
	cout << a << endl;	// output: 43

	int k = 42;
	// captured var which passing value is read-only
	// using 'mutable' to change its value
	// if so, parameter-list '()' is necessary
	auto lmd3 = [k] () mutable { cout << ++k << endl;};
	k = 0;
	lmd3();			// output: 43

	/* capture list: !!!
	 * [var1, &var2]: var1 passing value, var2 passing reference
	 * [&]: all passing reference implicitly
	 * [=]: all passing value implicitly
	 * [&, identifier_list]: vars in identifier_list passing value
	 *	explicitly, others passing reference implicitly
	 * [=, identifier_list]: vars in identifier_list passing reference
	 *	explicitly, others passing value implicitly
	 */
	vector<string> words({"a", "s", "d"});
	auto &outStream = cout;
	char c = '#';
	for_each(words.begin(), words.end(), 
			[&, c] (string const &str) {
				outStream << str << c;
			});
	for_each(words.begin(), words.end(),
			[=, &outStream] (string const &str) {
				outStream << str << c;
			});

	vector<int> vecInt({-3, -2, -1, 0, 7, 8, 9});
	transform(vecInt.begin(), vecInt.end(), vecInt.begin(),
			[] (int i) {
				// method 1:
				// return i > 0 ? i : -i;
				// method 2: ???
				if (i > 0) return i;
				else return -i;
			});
	for (auto const &i : vecInt)
		cout << i;	// output: 3210789
}

vector<string>::size_type CountStrSizeGT6(vector<string> const &words)
{
	return count_if(words.begin(), words.end(),
			[] (string const &word) {
				return word.size() > 6;
			});
}

int main(int argc, char **argv)
{
	CaptureNReturnEG();
	vector<string> vecStr({
			"123",
			"1234",
			"12345",
			"123456",
			"1234567",
			"1234567",
			"12345678"
			});
	cout << CountStrSizeGT6(vecStr) << endl; // output: 3

	return 0;
}

