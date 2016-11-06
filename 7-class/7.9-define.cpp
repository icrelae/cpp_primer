/* 2016.10.25 22:44
 * P_235
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
	public:
		string getName() const {return name;}
		string getAddress() const {return address;}
		string setName(istream &in) {
			in >> name;
			return name;
		}
		string setAddress(istream &in) {
			in >> address;
			return address;
		}
	private:
		string name;
		string address;
};

int main(int argc, char **argv)
{

	return 0;
}

