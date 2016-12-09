/* 2016.11.28 22:08
 * P_328
 * !!!
 * 1) compare of string: !!!
 * str1.compare(str2)
 * str1.compare(pos1, n1, str2)
 * str1.compare(pos1, n1, str2, pos2, n2)
 * str1.compare(cp)
 * str1.compare(pos1, n1, cp)
 * str1.compare(pos1, n1, cp, n2)
 * 2) numeric conversion of string: !!!
 * to_string(val): value to string, return string
 * stoi(str, posStr=0, base=10): 
 *	transffer str into number in base; 
 *	posStr is 'size_t *', using to keep index of first non-num charactor; 
 *	return int
 * stol(str, posStr=0, base=10): return long
 * stoul(str, posStr=0, base=10): reurn unsigned long
 * stoll(str, posStr=0, base=10): return long long
 * stoull(str, posStr=0, base=10): return unsigned long long
 * stof(str, posStr=0): return float
 * stod(str, posStr=0): return double
 * stold(str, posStr=0): return long double
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int SumVecStrInt(const vector<string> vec)
{
	int sum = 0;
	for (auto const str : vec)
		sum += stoi(str.substr(str.find_first_of("+-0123456789")));
	return sum;
}

double SumVecStrDbl(const vector<string> vec)
{
	double sum = 0;
	for (auto const str : vec)
		sum += stod(str.substr(str.find_first_of("+-.0123456789")));
	return sum;
}

int main(int argc, char **argv)
{
	vector<string> vecInt{"0", "-1", "+2", "3", "4", "5", "6"};
	vector<string> vecDbl{"0", "-1.1", "+2.1", "3.1", "4.11", ".5", "6"};

	cout << SumVecStrInt(vecInt) << endl;
	cout << SumVecStrDbl(vecDbl) << endl;

	return 0;
}

