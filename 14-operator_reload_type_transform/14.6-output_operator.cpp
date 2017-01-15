/* 2017.01.15 15:36
 * P_495
 * !!!
 * output operator shouldn't print control characters, especially line break !!!
 * input|output operator should not be the members, other wise: !!!
 *	class Sales_data {
 *		ostream& operator<<(ostream&);
 *	};
 *	Sales_data data;
 *	data << cout;		// owner should be the left operator
 */
#include <iostream>
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
};
istream& operator>>(istream &is, Sales_data &data)
{
	is >> data.bookNo >> data.units_sold >> data.revenue;
	return is;
}
ostream& operator<<(ostream &os, Sales_data &data)
{
	os << data.bookNo << data.units_sold << data.revenue;
	return os;
}
Sales_data operator+(Sales_data &dataA, Sales_data &dataB)
{
	Sales_data tmp;
	if (dataA.bookNo == dataB.bookNo) {
		tmp.bookNo = dataA.bookNo;
		tmp.units_sold = dataA.units_sold + dataB.units_sold;
		tmp.revenue = dataA.revenue + dataB.revenue;
	}
	return tmp;
}
Sales_data operator+=(Sales_data &dataA, Sales_data &dataB)
{
	if (dataA.bookNo == dataB.bookNo) {
		dataA.units_sold = dataA.units_sold + dataB.units_sold;
		dataA.revenue = dataA.revenue + dataB.revenue;
	}
	return dataA;
}

int main(int argc, char **argv)
{

	return 0;
}

