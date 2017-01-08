/* 2017.01.08 11:08
 * P_452
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
	public:
		Employee(): id(++x) { }
		Employee(const string &str): name(str), id(++x) { }
		Employee(const Employee &e) = default;
		Employee& operator=(const Employee &e) = default;
	private:
		static unsigned x;
		string name;
		unsigned id;
};
unsigned Employee::x = 0;

int main(int argc, char **argv)
{

	return 0;
}

