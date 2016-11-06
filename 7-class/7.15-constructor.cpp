/* 2016.10.29 00:23
 * P_239
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
	public:
		Person() = default;
		Person(string _name, string _address):
			name(_name), address(_address) {};
		string getName() const {return name;}
		string getAddress() const {return address;}
		void setName(istream &in) {
			in >> name;
		}
		void setAddress(istream &in) {
			in >> address;
		}
	private:
		string name;
		string address;
};

int main(int argc, char **argv)
{

	return 0;
}

