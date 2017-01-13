/* 2017.01.12 20:13
 * P_481
 * !!!
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

class HasPtr {
	public:
		HasPtr(): ps(new string), i(1) { }
		HasPtr(HasPtr &p): ps(new string(*p.ps)), i(p.i) {
			cout << "in copy-constructor" << endl;
		}
		~HasPtr() {
			delete ps;
		}
		HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {
			cout << "in move-constructor" << endl;
			p.ps = nullptr;
		}
		// here '=' can be copy-assignment as well as move-assignment !!!
		void swap(HasPtr &hp) {
			using std::swap;
			swap(ps, hp.ps);
			swap(i, hp.i);
		}
		HasPtr& operator=(HasPtr rhs) {
			cout << "in assignment" << endl;
			using std::swap;
			this->swap(rhs);
			return *this;
		}
	private:
		string *ps;
		unsigned i;
};
void MoveEG()
{
	HasPtr hp, hp2, hp3;
	hp = hp2;		// copy-assignment
	hp = std::move(hp3);	// move-assignment
	/* output:
	 *	in copy-constructor
	 *	in assignment
	 *	in move-constructor
	 *	in assignment
	 */
}

int main(int argc, char **argv)
{

	return 0;
}
