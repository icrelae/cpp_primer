/* 2016.12.24 21:00
 * P_379
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Sales_data {
	public:
		string isbn;
};
bool CompareIsbn(Sales_data const &a, Sales_data const &b)
{
	return a.isbn < b.isbn;
}

void TypeOfKeywordEG()
{
	Sales_data a;
	/* using custom compare-func instead of default '<' to compare keys !!!
	 * customComp have to be strict weak ordering
	 *	if k1<k2, k2<k1 is forbid
	 *	if k1<k2 && k2<k3, k1<k3
	 *	if !(k1<k2) && !(k2<k1), k1==k2
	 *	if k1==k2 && k2==k3, k1==k3
	 */
	set<Sales_data, decltype(CompareIsbn)*> setSalesdata(CompareIsbn);
}

int main(int argc, char **argv)
{
	map<string, list<int>> mapStrLstInt;

	return 0;
}

