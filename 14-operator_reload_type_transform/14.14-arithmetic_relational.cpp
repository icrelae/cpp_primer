/* 2017.01.16 09:00
 * P_497
 * !!!
 * arithmetic operator and relational operator should be non-member generally !!!
 * arguments always be 'const T&' due to changing obj is not need !!![
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Sales_data {
	public:
		Sales_data(string const &str = string()): bookNo(str) { }
		string bookNo;
		unsigned units_sold = 0;
		double revenue = 0;
		friend istream& operator>>(istream&, Sales_data&);
		friend ostream& operator<<(ostream&, const Sales_data&);
		friend Sales_data operator+(const Sales_data&, const Sales_data&);
		Sales_data& operator+=(const Sales_data&);
};
istream& operator>>(istream &is, Sales_data &data)
{
	double price;
	is >> data.bookNo >> data.units_sold >> price;
	data.revenue = data.units_sold * price;
	return is;
}
ostream& operator<<(ostream &os, const Sales_data &data)
{
	os << data.bookNo << ' ';
	os << data.units_sold << ' ';
	os << data.revenue;
	return os;
}
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data result;
	if (lhs.bookNo == rhs.bookNo) {
		result.bookNo = lhs.bookNo;
		result.units_sold = lhs.units_sold + rhs.units_sold;
		result.revenue = lhs.revenue + rhs.revenue;
	}
	return result;
}
Sales_data& Sales_data::operator+=(const Sales_data &data)
{
	if (bookNo == data.bookNo) {
		units_sold += data.units_sold;
		revenue += data.revenue;
	}
	return *this;
}

int main(int argc, char **argv)
{
	Sales_data data;
	string inputA("0-201-99999-9 10 24.95");
	string inputB("10 24.95 0-201-88888-8");

	istringstream iss;
	iss.str(inputA);
	iss >> data;
	cout << data << endl;
	iss.str(inputB);
	iss.clear();
	iss >> data;
	cout << data << endl;
	/* output:
	 *	0-201-99999-9 10 249.5
	 *	10 24 22.8
	 */

	return 0;
}

