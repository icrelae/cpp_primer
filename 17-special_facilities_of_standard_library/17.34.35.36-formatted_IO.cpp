/* 2017.04.07 21:33
 * P_673
 * manipulators !!!
 * in <iostream>
 * boolalpha		// print bool as alpha
 * noboolalpha		// print bool as 01
 * showbase		// print prefix for integer(octal and hex)
 * noshowbase
 * showpoint		// always print point for float
 * noshowpoint
 * showops		// pirnt '+' for nonnegative number
 * noshowpos
 * uppercase		// print '0X' for hex, 'E' for scientific notation
 * nouppercase
 * dec			// print integer as decimal
 * hex			// print integer as hex
 * oct			// print integer as octal
 * left			// print padding string right of value
 * right		// print padding string left of value
 * internal		// print padding string between symbol(+-) and nubmer
 * fixed		// print float as fixed decimal
 * scientific		// print float as scientific
 * hexfloat		// print float as hex
 * defaultfloat		// print float as decimal
 * unitbuf		// flush after each output
 * nounitbuf
 * skipws		// skip whitespace for '>>'
 * noskipws
 * flush		// flush ostream buffer
 * ends			// insert '\0', then flush ostream buffer
 * endl			// insert '\n', then flush ostream buffer
 * in <iomanip>
 * setw(n)		// read or write 'n' width characters
 * setfill(ch)		// padding use 'ch'
 * setprecision(n)	// set precision of float 'n'
 * setbase(b)		// output integer in scale 'b'
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

void ManipulatorEG()
{
	// boolalpha !!!
	cout << "default bool values: " << true << ' ' << false << endl
		<< "alpha bool values: " << boolalpha
		<< true << ' ' << false << endl;
	cout << "also alpha bool values: " << true << ' ' << false << endl;
	cout << noboolalpha;	// restore default bool value
	/* output:
	 *	default bool values: 1 0
	 *	alpha bool values: true false
	 *	also alpha bool values: true false
	 */

	// scale and showbase for integer !!!
	cout << showbase;	// show '0' for octal, '0x' for hex
	cout << "default: "
		<< 20 << ' ' << 1024 << endl;
	cout << "octal: " << oct
		<< 20 << ' ' << 1024 << endl;
	cout << "decimal: " << dec
		<< 20 << ' ' << 1024 << endl;
	cout << "hex: " << hex
		<< 20 << ' ' << 1024 << ' '
		<< uppercase
		<< 20 << ' ' << 1024 << ' '
		<< "asdf" << endl;;	// 'uppercase' doesn't affect string
	cout << dec << noshowbase;	// restore default decimal and no base
	cout << nouppercase;
	/* output:
	 *	default: 20 1024
	 *	octal: 024 02000
	 *	decimal: 20 1024
	 *	hex: 0x14 0x400 0X14 0X400 asdf
	 */

	// float
	cout << "precision: " << cout.precision()
		<< ", value: " << sqrt(2.0) << endl;
	cout.precision(12);		// print 12 numbers
	cout << "precision: " << cout.precision()
		<< ", value: " << sqrt(2.0) << endl;
	cout.precision(3);		// print 3 numbers
	cout << "precision: " << cout.precision()
		<< ", value: " << sqrt(2.0) << endl;
	/* output:
	 *	precision: 6, value: 1.41421
	 *	precision: 12, value: 1.41421356237
	 *	precision: 3, value: 1.41
	 */

	// padding
	int i = -16;
	double d = 3.14159;
	cout << "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n';
	cout << left		// left alignment
		<< "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n'
		<< right;	// restore default right alighment
	cout << right
		<< "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n';
	cout << internal
		<< "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n';
	cout << setfill('#')	// padding use '#' instead of ' '
		<< "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n'
		<< setfill(' ');
	/* output:
	 *	i:          -16next col
	 *	d:         3.14next col
	 *	i: -16         next col
	 *	d: 3.14        next col
	 *	i:          -16next col
	 *	d:         3.14next col
	 *	i: -         16next col
	 *	d:         3.14next col
	 *	i: -#########16next col
	 *	d: ########3.14next col
	 */
}

int main(int argc, char **argv)
{
	cout << uppercase << hexfloat << sqrt(2);
	// output: 0X1.6A09E667F3BCDP+0

	return 0;
}

