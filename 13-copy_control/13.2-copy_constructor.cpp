/* 2017.01.07 12:09
 * P_443
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_data {
	public:
		Sales_data() {};
		// invalid copy constructor
		Sales_data(Sales_data rhs);
	private:
		string bookNo;
		int units_sold = 0;
		double revenue = 0;
};
int main(int argc, char **argv)
{

	return 0;
}

