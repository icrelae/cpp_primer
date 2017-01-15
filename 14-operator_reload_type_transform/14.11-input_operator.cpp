/* 2017.01.15 16:49
 * P_496
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

