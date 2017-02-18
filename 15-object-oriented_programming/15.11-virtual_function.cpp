/* 2017.02.18 08:32
 * P_539
 * !!!
 * 1. dynamic resolve calling will happening only when calling virtual-func !!!
 * through pointer or reference
 * 2. declare 'virtual' for a virtual-func from base class in derived class is
 * not necessary !!!
 * 3. key word: override !!!
 * if 'override' is declared for some func but it not override any virtual func
 * of base class, error will be prompted(only virtual func can be overriden)
 * 4. key word: final !!!
 * if 'final' is declared for some func, any attempt of override will prompt error
 * 5. default argument of virtual-func: !!!
 * the value of default argument for virtual-func depends on static type of
 * object; it is better to using same default value in base and derived class
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
class Bulk_quote: public Quote {
	public:
		Bulk_quote() = default;
		Bulk_quote(const string&, double, size_t, double);
		double net_price(size_t) const override;
		void debug(ostream &os) const {
			Quote::debug(os);
			os << "min_quantity: " << min_qty << ' ';
			os << "discount: " << discount << ' ';
		}
	private:
		size_t min_qty = 0;		// min quantity for using discount
		double discount = 0.0;
};
Bulk_quote::Bulk_quote(const string &book, double p, size_t qty, double disc):
	Quote(book, p), min_qty(qty), discount(disc)
{
}
// const func should declare 'const' both in declaration and definition !!!
double Bulk_quote::net_price(size_t n) const
{
	return n * price * (n > min_qty ? discount : 1);
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

