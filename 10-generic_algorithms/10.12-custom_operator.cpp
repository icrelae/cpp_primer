/* 2016.12.13 22:10
 * P_345
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Sales_data {
	public:
		Sales_data(string const &str): bookNo(str) { }
		string bookNo;
		unsigned units_sold = 0;
		double revenue = 0;
};

bool CompareIsbn(Sales_data const &a, Sales_data const &b)
{
	return a.bookNo < b.bookNo;
}
int main(int argc, char **argv)
{
	vector<Sales_data> vecSalesData({
			Sales_data("ccc"), Sales_data("bbb"), 
			Sales_data("cca"), Sales_data("cbd")});
	sort(vecSalesData.begin(), vecSalesData.end(), CompareIsbn);
	for (auto const SalesData : vecSalesData)
		cout << SalesData.bookNo << ' ';

	return 0;
}

