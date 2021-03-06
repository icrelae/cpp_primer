/* 2017.02.24 22:03
 * P_554
 * !!!
 * if default constructor, copy-constructor, assignment operator or destructor in base-class is '=delete' inaccessible, the one in derived-class is '=delete' also.
 * if there's a inaccessible destructor in base-class, the default constructor and copy-constructor in derived-class is '=delete'
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct B {
	~B() = delete;
};
struct D: public B {

};
void EG()
{
	B *b = new B();
	//delete b;	// illegal, calling deleted destructor
	//B b1;		// illegal, calling deleted destructor
	//D d;		// illegal, calling deleted destructor
}

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
		//Disc_quote() = default;
		Disc_quote(const string &book, double price, size_t qty, double disc):
			Quote(book, price), quantity(qty), discount(disc) { }
		double net_price(size_t) const = 0;
	protected:
		size_t quantity = 0;
		double discount = 0.0;
};
class Bulk_quote: public Disc_quote {
	public:
		Bulk_quote() = default;
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
	//Bulk_quote bt;
	/* note: ‘Bulk_quote::Bulk_quote()’ is implicitly deleted because the
	 * default definition would be ill-formed:
	 */

	return 0;
}

