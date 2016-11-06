/* 2016.10.30 14:23
 * P_260
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_data {
	public:
		// a
		Sales_data(string s = ""): bookNo(s) { }
		// b
		Sales_data(string s, unsigned cnt, double rev): 
			bookNo(s), units_sold(cnt), revenue(rev * cnt) { }
		// c
		Sales_data(istream &is) { read(is, *this); }
		friend Sales_data &read(istream &is, Sales_data &data);
	private:
		string bookNo;
		unsigned units_sold, revenue;
};
Sales_data &read(istream &is, Sales_data &data)
{
	is >> data.bookNo >> data.units_sold >> data.revenue;
	return data;
}

int main(int argc, char **argv)
{
	// c
	Sales_data first_item(cin);
	// a
	Sales_data next;
	// a
	Sales_data last("9-999-99999-9");

	return 0;
}

