/* 2017.03.31 09:08
 * P_645
 * !!!
 * operate of bitset: !!!
 *	b.any();	// any bit of 'b' have been set?
 *	b.all();	// all bit of 'b' have been set?
 *	b.none();	// none of 'b' have been set?
 *	b.count();	// number of bit in 'b' be set
 *	b.size();	// constexpr func, reture number of bit in 'b'
 *	b.test(pos);	// if 'pos' of 'b' have been set, return true
 *	b.set(pos, v=true);
 *			// set 'pos' with 'v'
 *	b.set();	// set all bit in 'b'
 *	b.reset(pos);	// reset 'pos'
 *	b.reset();	// reset all
 *	b.flip(pos);	// reverse 'pos'
 *	b.flip();	// reverse all
 *	b[pos];		// if 'b' is 'const', return true|false
 *	b.to_ulong();	// return 'unsigned long'
 *	b.to_ullong();	// return 'unsigned long long', if 'b' is lager then
 *			// that type, throw overflow_error
 *	b.to_string(zero='0', one='1');
 *			// return a string
 *	os << b;	// output 01010101
 *	is >> b;	// input 01010101, when char is not '0' or '1' or
 *			// already read b.size() chars, input stop
 */
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int main(int argc, char **argv)
{
	bitset<32> b1("0111010010000100000001");
	bitset<32> b2;

	for (size_t i = 0; i < b1.size(); ++i) {
		if (true == b1.test(i))
			b2.set(i);
		else
			b2.reset(i);
		b2[i] = b1[i];
	}

	return 0;
}

