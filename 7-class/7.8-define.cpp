/* 2016.10.17 21:36
 * P_233
 * because pirnt shouldn't modify value
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
istream& read(istream &in, Sales_data &item)
{
	in >> item.bookNo;
	in >> item.units_sold;
	in >> item.revenue;
	return in;
}
ostream& print(ostream &out, const Sales_data &item)
{
	out << item.bookNo << endl;
	out << item.units_sold << endl;
	out << item.revenue << endl;
	return out;
}
int main(int argc, char **argv)
{
	Sales_data total;
	if (read(cin, total)) {
		Sales_data trans;
		while (read(cin, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total);
				total = trans;
			}
		}
		print(cout, total);
	} else {
		cerr << "no data" << endl;
	}

	return 0;
}

