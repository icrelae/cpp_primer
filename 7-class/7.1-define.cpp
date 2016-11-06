/* 2016.10.16 16:40
 * P_230
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

istream &operator >>(istream &in, Sales_data a)
{
	in >> a.bookNo >> a.units_sold >> a.revenue;
	return in;
}
ostream &operator <<(ostream &out, Sales_data a)
{
	out << a.bookNo << ' ';
	out << a.units_sold << ' ';
	out << a.revenue << endl;
	return out;
}
int main(int argc, char **argv)
{
	Sales_data total;
	if (cin >> total) {
		Sales_data trans;
		while (cin >> trans) {
			if (trans.bookNo == total.bookNo) {
				total += trans;
			} else {
				cout << total << endl;
				total = trans;
			}
		}
	} else {
		cout << "no data" << endl;
	}

	return 0;
}

