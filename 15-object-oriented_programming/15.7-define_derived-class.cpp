/* 2017.02.17 08:38
 * P_533
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
	private:
		string bookNo;
	protected:
		double price = 0.0;
};

class Limit_quote: public Quote {
	public:
		Limit_quote() = default;
		Limit_quote(const string&, double, size_t, double);
		double net_price(size_t) const override;
	private:
		size_t max_qty = 0;		// min quantity for using discount
		double discount = 0.0;
};
Limit_quote::Limit_quote(const string &book, double p, size_t qty, double disc):
	Quote(book, p), max_qty(qty), discount(disc)
{
}
// const func should declare 'const' both in declaration and definition
double Limit_quote::net_price(size_t n) const
{
	double ret = n * price * discount;
	ret += (n > max_qty ? n - max_qty : 0) * price * (1 - discount);
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
	Quote quote("asdf", 10);
	Limit_quote bquote("qwer", 10, 5, 0.5);

	print_total(cout, quote, 10);
	print_total(cout, bquote, 10);
	print_total(cout, bquote, 5);
	/* output:
	 *	ISBN: asdf # sold: 10 total due: 100
	 *	ISBN: qwer # sold: 10 total due: 75
	 *	ISBN: qwer # sold: 5 total due: 25
	 */

	return 0;
}

