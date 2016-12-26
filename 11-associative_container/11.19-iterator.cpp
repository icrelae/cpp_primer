/* 2016.12.25 11:40
 * P_383
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Sales_data {
	public:
		Sales_data(string const &strIsbn): isbn(strIsbn) {}
		string isbn;
};
bool CompareIsbn(Sales_data const &a, Sales_data const &b)
{
	return a.isbn < b.isbn;
}
int main(int argc, char **argv)
{
	multiset<Sales_data, decltype(CompareIsbn)*> bookstore(CompareIsbn);
	bookstore.insert(Sales_data("asdf"));
	multiset<Sales_data, bool(*)(Sales_data const &, Sales_data const &)>::iterator itMset= bookstore.begin();
	cout << itMset->isbn << endl;
	// output: asdf

	return 0;
}

