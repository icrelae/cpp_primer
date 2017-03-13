/* 2017.03.12 20:53
 * P_583
 */
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

template<unsigned N, unsigned M>
// site 'inline' or 'constexpr' before return type !!!
inline int FuncEG(const char (&p1)[N], const char (&p2)[M])
{
	cout << N << ' ' << M;
	return strcmp(p1, p2);
}
void TemplateEG()
{
	char cstrA[] = "hi";
	char cstrB[] = "mom";
	// invalid according to book, but it is valid
	cout << FuncEG(cstrA, cstrB) << endl;
	cout << FuncEG("hi", "mom") << endl;
	/* output:
	 *	3 4 -5
	 *	3 4 -5
	 */
}

class Sales_data {
	public:
		Sales_data(string const &str): bookNo(str) { }
		string bookNo;
		unsigned units_sold = 0;
		double revenue = 0;
		explicit operator string() const { return bookNo;}
		explicit operator double() const { return revenue;}
};
template<typename T>
int compare(T a, T b)
{
	return a < b;
}

int main(int argc, char **argv)
{
	Sales_data a("asd");
	Sales_data b("asd");
	//compare(a, b);
	// error: no match for ‘operator<’ (operand types are ‘Sales_data’ and ‘Sales_data’)

	return 0;
}

