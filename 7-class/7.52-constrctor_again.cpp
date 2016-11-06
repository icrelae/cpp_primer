/* 2016.10.31 22:19
 * P_267
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main(int argc, char **argv)
{
	Sales_data item = {"978-05090353403", 25, 15.99};

	return 0;
}

