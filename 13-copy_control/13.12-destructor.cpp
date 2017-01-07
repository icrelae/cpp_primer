/* 2017.01.07 21:01
 * P_446
 * 3
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_data {
	public:
		string isbn;
};

bool fcn(Sales_data const *trans, Sales_data accum)
{
	Sales_data item1(*trans), item2(accum);
	return item1.isbn != item2.isbn;
}

int main(int argc, char **argv)
{

	return 0;
}

