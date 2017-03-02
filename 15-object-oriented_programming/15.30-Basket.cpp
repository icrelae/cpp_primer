/* 2017.02.28 20:29
 * P_562
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <utility>

using namespace std;

class Quote {
	public:
		Quote() = default;
		Quote(const string &book, double sales_price):
			bookNo(book), price(sales_price) { }
		// copy constructor
		Quote(const Quote&) = default;
		// move constructor
		Quote(const Quote &&q) noexcept :
			bookNo(std::move(q.bookNo)),
			price(std::move(q.price)) { }
		virtual ~Quote() = default;
		// copy =()
		Quote& operator =(const Quote &q) {
			if (this != &q) {
				bookNo = q.bookNo;
				price = q.price;
			}
			return *this;
		}
		// move =()
		Quote& operator =(const Quote &&q) noexcept {
			if (this != &q) {
				bookNo = std::move(q.bookNo);
				price = std::move(q.price);
			}
			return *this;
		}
		string isbn() const { return bookNo;}
		virtual double net_price(size_t n) const { return n * price;}
		virtual void debug(ostream &os) const {
			os << "bookNo: " << bookNo << ' ';
			os << "price: " << price << ' ';
		}
		virtual Quote* clone() const & { return new Quote(*this);}
		virtual Quote* clone() && { return new Quote(std::move(*this));}
	private:
		string bookNo;
	protected:
		double price = 0.0;
};
class Disc_quote: public Quote {
	public:
		Disc_quote() = default;
		Disc_quote(const string &book, double price, size_t qty, double disc):
			Quote(book, price),
			quantity(qty),
			discount(disc) { }
		Disc_quote(const Quote &q):Quote(q) { };
		// copy constructor
		Disc_quote(const Disc_quote &dq):
			Quote(dq),
			quantity(dq.quantity),
			discount(dq.discount) { };
		// move constructor
		Disc_quote(const Disc_quote &&dq) noexcept :
			Quote(std::move(dq)),
			quantity(std::move(dq.quantity)),
			discount(std::move(dq.discount)) { }
		virtual ~Disc_quote() = default;
		// copy =()
		Disc_quote& operator =(const Disc_quote &dq) {
			Quote::operator =(dq);
			quantity = dq.quantity;
			discount = dq.discount;
			return *this;
		}
		// move =()
		Disc_quote& operator =(const Disc_quote &&dq) noexcept {
			Quote::operator =(std::move(dq));
			quantity = std::move(dq.quantity);
			discount = std::move(dq.discount);
			return *this;
		}
		virtual double net_price(size_t) const override = 0;
	protected:
		size_t quantity = 0;
		double discount = 0.0;
};
class Bulk_quote: public Disc_quote {
	public:
		Bulk_quote() = default;
		// copy constructor
		Bulk_quote(const Bulk_quote &bq): Disc_quote(bq) { };
		// move constructor
		Bulk_quote(const Bulk_quote &&bq) noexcept :
			Disc_quote(std::move(bq)) { }
		Bulk_quote(const string &book, double p, size_t qty, double disc):
			Disc_quote(book, p, qty, disc) { }
		virtual ~Bulk_quote() = default;
		// copy =()
		Bulk_quote& operator =(const Disc_quote &dq) {
			Disc_quote::operator =(dq);
			return *this;
		}
		// move =()
		Bulk_quote& operator =(const Disc_quote &&dq) noexcept {
			Disc_quote::operator =(std::move(dq));
			return *this;
		}
		double net_price(size_t n) const override {
			return n * price * (n > quantity ? discount : 1);
		}
		void debug(ostream &os) const {
			Quote::debug(os);
			os << "min_quantity: " << quantity << ' ';
			os << "discount: " << discount << ' ';
		}
		// lvalue call this
		virtual Bulk_quote* clone() const & override {
			return new Bulk_quote(*this);
		}
		// rvalue call this
		virtual Bulk_quote* clone() && override {
			return new Bulk_quote(std::move(*this));
		}
};

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " # sold: " << n
		<< " total due: " << ret
		<< endl;
	return ret;
}

class Basket {
	public:
		/* hide pointer and simulate virtual copy !!!
		 * first add_item() cannot hide pointer, because when calling this
		 * function, the args maybe as:
		 *	make_shared<Quote>("bookNo", 1), 
		 * 	make_shared<Bulk_quote>("bookNo", 1, 1, 1);
		 * so we add last two add_item(), you can add item as:
		 *	Quote q; Bulk_quote bq;
		 *	add_item(q); add_item(bq);
		 * but if you pass 'q' or 'bq' to 'items.insert()' directly as below:
		 *	items.insert(q),
		 *	items.insert(bq);
		 * it is wrong because items will allocate memory only for 'Quote'
		 * instead of 'Bulk_quote', items won't know the arg's dynamic
		 * type;
		 * so we add clone() to return its dynamic type pointer, then
		 * calling insert() as below:
		 *	items.insert(q.clone()) => items.insert(Quote*);
		 *	items.insert(bq.clone()) => items.insert(Bulk_quote*);
		 * clone() need to tell lvalue(copy) or rvalue(move), so we add
		 * move-constructor to base and devived; copy-constructor,
		 * copy-assignment, move-constructor, move-assignment and
		 * destructor should e consider as a whole;
		 */
		void add_item(const shared_ptr<Quote> &sale) {
			items.insert(sale);
		}
		void add_item(const Quote &sale) {
			items.insert(shared_ptr<Quote>(sale.clone()));
		}
		void add_item(const Quote &&sale) {
			items.insert(shared_ptr<Quote>(std::move(sale).clone()));
		}
		double total_receipt(ostream&) const;
	private:
		static bool compare(const shared_ptr<Quote> &lhs,
				const shared_ptr<Quote> &rhs) {
			return lhs->isbn() < rhs->isbn();
		}
		// using compare() to order multiset !!!
		multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};
double Basket::total_receipt(ostream &os) const
{
	double sum = 0;
	for (auto iter = items.cbegin();
			iter != items.cend();
			iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "taltal sale: " << sum << endl;
	return sum;
}

int main(int argc, char **argv)
{

	Basket basket;
	for (unsigned i = 0; i < 10; ++i) {
		Bulk_quote bq("bq01", 10, 10, 0.5);
		basket.add_item(bq);
	}
	basket.total_receipt(cout);
	for (unsigned i = 0; i < 10; ++i) {
		Bulk_quote bq("bq02", 10, 5, 0.5);
		basket.add_item(bq);
	}
	basket.total_receipt(cout);
	for (unsigned i = 0; i < 10; ++i) {
		Quote q("q01", 10);
		basket.add_item(q);
	}
	basket.total_receipt(cout);
	/* output: 
	 *	ISBN: bq01 # sold: 10 total due: 100
	 *	taltal sale: 100
	 *	ISBN: bq01 # sold: 10 total due: 100
	 *	ISBN: bq02 # sold: 10 total due: 50
	 *	taltal sale: 150
	 *	ISBN: bq01 # sold: 10 total due: 100
	 *	ISBN: bq02 # sold: 10 total due: 50
	 *	ISBN: q01 # sold: 10 total due: 100
	 *	taltal sale: 250
	 */

	return 0;
}

