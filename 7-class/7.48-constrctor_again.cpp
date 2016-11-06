/* 2016.10.30 16:45
 * P_266
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_data
{
	public:
		Sales_data() = default;
		Sales_data(string str): Sales_data(str, 0, 0) { }
		Sales_data(istream &in)
		{
			read(in);
		}
		Sales_data(string bookNo, 
				unsigned int units_sold, 
				double revenue);
		Sales_data& combine(const Sales_data &rhs);
		istream& read(istream &in);
		ostream& print(ostream &out);
		string isbn() const;
		inline double avg_price();
	private:
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
istream& Sales_data::read(istream &in)
{
	in >> bookNo;
	in >> units_sold;
	in >> revenue;
	return in;
}
ostream& Sales_data::print(ostream &out)
{
	out << bookNo << endl;
	out << units_sold << endl;
	out << revenue << endl;
	return out;
}
inline double Sales_data::avg_price()
{
	return (revenue / units_sold);
}
int main(int argc, char **argv)
{
	string null_isbn("9-999-99999-9");
	Sales_data item1(null_isbn);
	/* string to string
	 */
	Sales_data item2("9-999-99999-9");
	/* "" to string
	 */

	return 0;
}

