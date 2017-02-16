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
	private:
		size_t val;
};
struct LongDouble {
	LongDouble operator+(const SmallInt&);
};
LongDouble operator+(LongDouble, double);

int main(int argc, char **argv)
{
	SmallInt si;
	LongDouble ld;
	ld = si + ld;	// wrong
	ld = ld + si;	// LongDouble::operator+(SmallInt)

	return 0;
}

