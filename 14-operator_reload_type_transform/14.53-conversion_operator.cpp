/* 2017.02.15 22:02
 * P_522
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SmallInt {
	public:
		SmallInt(int i = 0): val(i) { }
		explicit operator int() const { return val;}
		explicit operator bool() const { return val;}
		friend double operator+(const SmallInt&, const double&);
	private:
		size_t val;
};
double operator+(const SmallInt &si, const double &d)
{
	return si.val + d;
}

int main(int argc, char **argv)
{
	SmallInt si;
	double d = si + 3.14;

	return 0;
}

