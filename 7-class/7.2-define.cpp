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
		Sales_data(string bookNo, unsigned int units_sold, double revenue);
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
int main(int argc, char **argv)
{

	return 0;
}

