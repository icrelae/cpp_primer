/* 2017.02.27 21:24
 * P_558
 * !!!
 * access level of 'using base::constructor': !!!
 *	'using base::constructor' in anywhere won't change access level, but 'using
 *	base::common_func' will
 * 'explicit' or 'constexpr' of 'using base::constructor': !!!
 *	'using' cannot specify 'explicit' or 'constexpr', they are all inherit from
 *	base-class
 * default arguments for 'using base::constructor': !!!
 *	default arguments won't be inherited, derived-class will generate many
 *	constructors, each constructor omit one default argument
 *	eg:
 *		Base(int a, int b = 0);	// in base class
 *		using Base::Base;		// in derived class
 *		// equal to:
 *		//Derived(int);
 *		//Derived(int, int);
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
		Quote(const Quote&) = default;
		Quote& operator =(const Quote&) = default;
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
		//Disc_quote() = default;
		Disc_quote(const Quote &dq):Quote(dq) { };
		Disc_quote& operator =(const Disc_quote &dq)
		{
			Quote::operator =(dq);
			quantity = dq.quantity;
			discount = dq.discount;
			return *this;
		}
		Disc_quote(const string &book, double price, size_t qty, double disc):
			Quote(book, price), quantity(qty), discount(disc) { }
		double net_price(size_t) const = 0;
	protected:
		size_t quantity = 0;
		double discount = 0.0;
};
class Bulk_quote: public Disc_quote {
	public:
		//Bulk_quote() = default;
		//Bulk_quote(const Bulk_quote &bq):Disc_quote(bq) { };
		using Disc_quote::Disc_quote;	// same with two destructor above
		Bulk_quote& operator =(const Disc_quote &dq)
		{
			Disc_quote::operator =(dq);
			return *this;
		}
		Bulk_quote(const string&, double, size_t, double);
		double net_price(size_t) const override;
		void debug(ostream &os) const {
			Quote::debug(os);
			os << "min_quantity: " << quantity << ' ';
			os << "discount: " << discount << ' ';
		}
};
Bulk_quote::Bulk_quote(const string &book, double p, size_t qty, double disc):
	Disc_quote(book, p, qty, disc)
{
}
// const func should declare 'const' both in declaration and definition !!!
double Bulk_quote::net_price(size_t n) const
{
	return n * price * (n > quantity ? discount : 1);
}

int main(int argc, char **argv)
{

	return 0;
}

