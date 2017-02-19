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

class Limit_quote: public Disc_quote {
	public:
		Limit_quote() = default;
		Limit_quote(const string&, double, size_t, double);
		double net_price(size_t) const override;
};
Limit_quote::Limit_quote(const string &book, double p, size_t qty, double disc):
	Disc_quote(book, p, qty, disc)
{
}
// const func should declare 'const' both in declaration and definition
double Limit_quote::net_price(size_t n) const
{
	double ret = n * price * discount;
	ret += (n > quantity ? n - quantity : 0) * price * (1 - discount);
	return ret;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " # sold: " << n
		<< " total due: " << ret
		<< endl;
	return ret;
}

int main(int argc, char **argv)
{

	return 0;
}

