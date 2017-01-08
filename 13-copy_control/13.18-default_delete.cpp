/* 2017.01.08 11:08
 * P_452
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DefaultEG {
	public:
		// in-class 'default' will be 'inline function' !!!
		DefaultEG() = default;
		DefaultEG(const DefaultEG&) = default;
		~DefaultEG() = default;
		// out-class 'default' won't !!!
		DefaultEG & operator=(const DefaultEG&);
};
DefaultEG & DefaultEG::operator=(const DefaultEG&) = default;

class DeleteEG {
	public:
		DeleteEG(int &x): a(x) { }
		DeleteEG(const DeleteEG&) = delete;
		// destructor can't be 'delete' !!!
		~DeleteEG() = default;
		int &a;
};
/* !!!
 * for class which have reference or const member, default constructor and
 * copy-assignment operator will be deleted automatically
 */
void DeleteFuncEG()
{
	int x;
	DeleteEG a(x), b(x);
	// invalid use of deleted function 'operator=()'
	//b = a;
}

class Employee {
	public:
		string name;
		unsigned id;
		Employee(): id(++x) { }
		Employee(const string &str): name(str), id(++x) { }
	private:
		static unsigned x;
};
unsigned Employee::x = 0;

int main(int argc, char **argv)
{

	return 0;
}

