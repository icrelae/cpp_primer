/* 2017.02.19 09:43
 * P_542
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Quote {
	public:
		Quote() = default;
		Quote(const string &book, double sales_price):
			bookNo(book), price(sales_price) { }
		string isbn() const { return bookNo;}
		virtual double net_price(size_t n) const { return n * price;}
		virtual void debug(ostream &os) const {
			os << "bookNo: " << bookNo << ' ';
			os << "price: " << price << ' ';
		}
	private:
		string bookNo;
	protected:
		double price = 0.0;
};

class Disc_quote: public Quote {
	public:
		Disc_quote() = default;
		Disc_quote(const string &book, double price, size_t qty, double disc):
			Quote(book, price), quantity(qty), discount(disc) { }
		double net_price(size_t) const = 0;
	protected:
		size_t quantity = 0;
		double discount = 0.0;
};

int main(int argc, char **argv)
{
	Disc_quote dr;
	/*
	 * error: cannot declare variable ‘dq’ to be of abstract type ‘Disc_quote’
	 *   Disc_quote dq;
	 * 	     ^~
	 * note:   because the following virtual functions are pure within ‘Disc_quote’:
	 *   class Disc_quote: public Quote
	 */

	return 0;
}

