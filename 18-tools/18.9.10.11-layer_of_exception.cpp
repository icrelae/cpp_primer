/* 2017.04.11 19:05
 * P_695
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* layer of 'exception' !!!
 * exception
 * |_	bad_cast
 * |_	runtime_error
 * |	|_	overflow_error
 * |	|_	underflow_error
 * |	|_	range_error
 * |_	logic_error
 * |	|_	domain_error
 * |	|_	invalid_argument
 * |	|_	out_of_range
 * |	|_	length_error
 * |_	bad_alloc
 */

class out_of_stock: public std::runtime_error {
	public:
		explicit out_of_stock(const string &s):
			std::runtime_error(s) {
		}
};
class isbn_mismatch: public std::logic_error {
	public:
		explicit isbn_mismatch(const string &s):
			std::logic_error(s) {
		}
		isbn_mismatch(const string &s,
				const string &lhs, const string &rhs):
			logic_error(s), left(lhs), right(rhs) {
		}
		const string left, right;
};
class Sales_data {
	public:
		Sales_data(const string &s): isbn(s) { }
		Sales_data& operator+=(const Sales_data &rhs) {
			if (isbn != rhs.isbn)
				throw isbn_mismatch("wrong isbns", isbn, rhs.isbn);
			return *this;
		}
		string isbn;
};

int main(int argc, char **argv)
{
	Sales_data s1("asdf"), s2("qwer");
	try {
		s1 += s2;
	} catch (const isbn_mismatch &e) {
		cout << "in catch: " << e.what() << endl;
		cout << "left: " << s1.isbn << endl;
		cout << "right: " << s2.isbn << endl;
	}
	s1 += s2;

	return 0;
}

