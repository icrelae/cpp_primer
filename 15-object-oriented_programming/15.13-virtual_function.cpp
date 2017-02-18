/* 2017.02.18 08:32
 * P_539
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class base {
	public:
		string name() { return basename;}
		virtual void print(ostream &os) { os << basename;}
	private:
		string basename;
};
class derived: public base {
	public:
		void print(ostream &os) {
			// explicitly calling base virtual-func
			base::print(os);
			os << " " << i;
		}
	private:
		int i;
};

int main(int argc, char **argv)
{

	return 0;
}

