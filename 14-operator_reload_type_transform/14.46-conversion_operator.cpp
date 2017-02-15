/* 2017.02.15 21:07
 * P_517
 * no, it's misleading
 * yes, prevent implicit conversion
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SmallInt {
	public:
		SmallInt(int i = 0): val(i) { }
		explicit operator int() const { return val;}
		explicit operator bool() const { return val;}
	private:
		size_t val;
};
void ConversionOpEG()
{
	SmallInt si = 3;
	//si + 3;			// wrong, because explicit
	static_cast<int>(si) + 3;	// correct
	// exception for explicit conversion-op
	if (si) { }
	while (si) { break;}
	do { } while (si);
	for ( ; si; ) { break;}
	!si, si || si, si && si;
	si ? true : false;
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

int main(int argc, char **argv)
{
	Sales_data item("asdf");
	cout << static_cast<string>(item) << endl;
	cout << static_cast<double>(item) << endl;
	// output: asdf 0

	return 0;
}

