/* 2016.12.14 21:00
 * P_349
 * !!!
 * lambda: [capture list] (parameter list) -> return type {function body} !!!
 * capture list: usually empty, contains local nonstatic variables list of function where lambda belongs to !!!
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void LambdaEG()
{
	// define lambda
	// parameter list and return type are optional, others are required !!!
	cout << [] {return 0;} << endl;
	// output: 1
	auto lambda = [] {return 0;};
	cout << lambda << ' ' << lambda() << endl;
	// output: 1 0

	// deliver parameters
	// lambda don't support default parameter value !!!
	vector<string> vecStr({"abc", "ab", "b"});
	stable_sort(vecStr.begin(), vecStr.end(), 
			[] (string const &strA, string const &strB) {
				return strA.size() < strB.size();
			});
	for (auto const str : vecStr)
		cout << str << ' ';
	cout << endl;
	// output: b ab abc 

	// capture list
	unsigned uintSize = 2;
	/* find_if(itBeg, itEnd, customCompare) !!!
	 * return first iterator which customCompare() return true
	 */
	auto itStr = find_if(vecStr.begin(), vecStr.end(), 
			[uintSize] (string const &str) -> bool {
				return (str.size() >= uintSize);
			});
	cout << *itStr << endl;
	// output: ab

	// for_each(itBeg, itEnd, func) !!!
	// heres lambda using a uncaptured name: cout; !!!
	// due to 'cout' is declared upper layer of LambdaEG()
	// so its not necessary put 'cout' into capture list;
	// besides, static var could be used without writing in
	// capture list;
	for_each(itStr, vecStr.end(), 
			[] (string const &str) {
				cout << str << ' ';
			});
	cout << endl;
	// output: ab abc 
}
int Sum(int const &intA, int const &intB)
{
	auto lmdSumInt = [] (int const &intA, int const &intB) {
		return (intA + intB);
	};
	return lmdSumInt(intA, intB);
}
int main(int argc, char **argv)
{
	LambdaEG();
	cout << Sum(2, 3) << endl;

	return 0;
}

