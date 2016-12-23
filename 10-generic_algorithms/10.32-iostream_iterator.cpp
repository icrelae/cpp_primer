/* 2016.12.23 08:38
 * P_362
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

class Sales_item {
	public:
		Sales_item():isbn(""), unit_sold(0), revenue(0) {}
		string isbn;
		unsigned unit_sold;
		double revenue;
};
istream& operator >>(istream &is, Sales_item &salesItem)
{
	is >> salesItem.isbn >> salesItem.unit_sold >> salesItem.revenue;
	return is;
}
ostream& operator <<(ostream &os, Sales_item const &salesItem)
{
	os << "isbn: " << salesItem.isbn << "; ";
	os << "unit: " << salesItem.unit_sold << "; ";
	os << "reve: " << salesItem.revenue << endl;
	return os;
}
Sales_item operator +(Sales_item const &salesItemA, Sales_item const &salesItemB)
{
	Sales_item result;
	if (salesItemA.isbn == salesItemB.isbn) {
		result.isbn = salesItemA.isbn;
		result.unit_sold = salesItemA.unit_sold + salesItemB.unit_sold;
		result.revenue = salesItemA.revenue + salesItemB.revenue;
	}
	return result;
}
void ReadNAccumulateSalesItems()
{
	vector<Sales_item> vecSalesItem;
	istream_iterator<Sales_item> itIstream(cin), itEof;
	while (itIstream != itEof) {
		vecSalesItem.push_back(*itIstream++);
	}
	sort(vecSalesItem.begin(), vecSalesItem.end(),
			[] (Sales_item const &itemA, Sales_item const &itemB) {
				return itemA.isbn < itemB.isbn;
			});
	vector<Sales_item>::const_iterator itSalesItemBeg = vecSalesItem.cbegin();
	vector<Sales_item>::const_iterator itSalesItemEnd =
		find_if(itSalesItemBeg, vecSalesItem.cend(),
				[itSalesItemBeg] (Sales_item const &itemA) {
					return itemA.isbn != itSalesItemBeg->isbn;
				});
	while (itSalesItemBeg != vecSalesItem.cend()) {
		cout << accumulate(itSalesItemBeg+1, itSalesItemEnd, *itSalesItemBeg);
		itSalesItemBeg = itSalesItemEnd;
		itSalesItemEnd = find_if(itSalesItemBeg, vecSalesItem.cend(),
				[itSalesItemBeg] (Sales_item const &itemA) {
					return itemA.isbn != itSalesItemBeg->isbn;
				});
	} 
}
int main(int argc, char **argv)
{
	ReadNAccumulateSalesItems();

	return 0;
}

