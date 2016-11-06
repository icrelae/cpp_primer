/* 2016.10.17 21:36
 * P_233
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_data
{
	public:
		Sales_data(string bookNo = "", 
				unsigned int units_sold = 0, 
				double revenue = 0);
		Sales_data& combine(const Sales_data &rhs);
		string isbn() const;
		string bookNo;
		unsigned int units_sold = 0;
		double revenue = 0.0;
};
Sales_data::Sales_data(string bookNo, unsigned int units_sold, double revenue)
{
	this->bookNo = bookNo;
	this->units_sold = units_sold;
	this->revenue = revenue;
}
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
string Sales_data::isbn() const
{
	return bookNo;
}
// io objects fobits object-copy, so it always using reference on parameters and return value!!!
istream& operator >>(istream &in, Sales_data &sales_data)
{
	in >> sales_data.bookNo;
	in >> sales_data.units_sold;
	in >> sales_data.revenue;
	return in;
}
ostream& operator <<(ostream &out, Sales_data &sales_data)
{
	out << "bookNo: " << sales_data.bookNo << endl;
	out << "units_sold: " << sales_data.units_sold << endl;
	out << "revenue: " << sales_data.revenue << endl;
	return out;
}
int main(int argc, char **argv)
{
	Sales_data total;
	if (cin >> total) {
		Sales_data trans;
		while (cin >> trans) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				cout << total << endl;
				total = trans;
			}
		}
		cout << total << endl;
	} else {
		cerr << "no data" << endl;
	}

	return 0;
}

