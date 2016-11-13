/* 2016.11.09 21:49
 * P_287
 */
#include <iostream>
#include <fstream>
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
	if (argc < 3)
		return -1;
	ifstream ifs(argv[1]);
	ofstream ofs(argv[2]);
	Sales_data total;
	if (read(ifs, total)) {
		Sales_data trans;
		while (read(ifs, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(ofs, total);
				total = trans;
			}
		}
		print(ofs, total);
	} else {
		cerr << "no data" << endl;
	}
	ifs.close();
	ofs.close();

	return 0;
}

