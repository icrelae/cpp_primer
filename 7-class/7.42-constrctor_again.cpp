/* 2016.10.30 16:23
 * P_262
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
	public:
		Book(): Book("unknown", 0) { }
		Book(string _no, double _price): no(_no), price(_price) { }
	private:
		string no;
		double price;
};

int main(int argc, char **argv)
{

	return 0;
}

