/* 2016.11.26 16:19
 * P_322
 * !!!
 * e.g. of define string and substring !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void DefineStringEG()
{
#define DEF	1
#if DEF
#define DefNShowStr(...)	\
	do {					\
		std::string str(__VA_ARGS__);	\
		std::cout << str << ' ';	\
	} while (0)
#else
#define DefNShowStr(...)	{}
#endif
	const char *cp = "123456789";
	const string str0(cp);
	DefNShowStr(cp+1, 6);
	DefNShowStr(str0, 2);
	DefNShowStr(str0, 0, 3);
	DefNShowStr(str0, 2, 3);
	// output: 234567 3456789 123 345
}
void SubStringEG()
{
	string str0("123456789");
	cout << str0.substr(0, 5) << ' ';
	cout << str0.substr(6) << ' ';
	cout << str0.substr(6, 11) << ' ';
	// output: 12345 789 789 
}

string DefStrFromVec(vector<char> vecCh)
{
	string str(vecCh.begin(), vecCh.end());
	return str;
}
int main(int argv, char **argc)
{
	vector<char> vecCh;
	vecCh.assign(3, 'a');
	cout << DefStrFromVec(vecCh) << ' ';
	vecCh.assign(3, 'c');
	cout << DefStrFromVec(vecCh) << ' ';
	return 0;
}

