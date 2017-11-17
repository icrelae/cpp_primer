/* 2017.03.30 21:13
 * !!!
 * P_642
 * define bitset: !!!
 *	header: <bitset>
 *	bitset<n> b;
 *	bitset<n> b(u);
 *	explicit bitset<n> b(str, pos, m=string::npos, zero='0', one='1');
 *			// copy 'm' chars from 'pos' of 's';
 *			// EG: bitset<8> b(string("abab"), 0, 3, 'a', 'b');
 *			// 'str' can include only 'zero' or 'one', other wise
 *			// exception 'invalid_argument' will be threw;
 *	explicit bitset<n> b(cptr, pos, m=string::npos, zero=0, one=1);
 */
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

void bitsetEG()
{
	string str = "abaaabaa";
	size_t size = 8;
	bitset<8> b(str, 0, 3, 'a', 'b');
	cout << b << endl;
	// output: 00000010
	for (auto x = 0; x < size; ++x)
		cout << b[x] << ' ';
	// output: 0 1 0 0 0 0 0 0 
}

int main(int argc, char **argv)
{
	bitset<64> bitvec(32);		// b(0x10)
	bitset<32> bvb(1010101);	// b(0xf69b5)

	string bstr;
	cin >> bstr;
	bitset<8> bvc(bstr);		// b(string, 0, string::npos, '0', '1')

	return 0;
}

