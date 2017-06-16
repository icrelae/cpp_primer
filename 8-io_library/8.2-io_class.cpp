/* 2016.11.06 11:06
 * P_280
 * !!!
 * std::iostate:
 *	strm::goodbit	0
 *	strm::badbit	1, whether crashed
 *	strm::eofbit	2, whether meet end of file
 *	strm::failbit	4, whether IO operate failed
 * clear(std::iostate s):
 *	override current state using 's'
 *	clear() equal to clear(strm.goodbit)
 * setstate(std::iostate s):
 *	set correspond iostate to 1 for s
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

istream &ShowStreamStateBit(istream &is)
{
	/* wrong way to get state bit */
	//cout << "badbit: " << is.badbit << ' ';
	//cout << "eofbit: " << is.eofbit << ' ';
	//cout << "failbit: " << is.failbit << ' ';
	//cout << "goodbit: " << is.goodbit << ' ';
	/* right way to get state bit !!! */
	cout << "badbit: " << is.bad() << ' ';
	cout << "eofbit: " << is.eof() << ' ';
	cout << "failbit: " << is.fail() << ' ';
	cout << "goodbit: " << is.good() << ' ';
	cout << endl;
	return is;
}
istream &Read(istream &is)
{
	string buf;
	ShowStreamStateBit(is);	// badbit: 0 eofbit: 0 failbit: 0 goodbit: 1
	while (is >> buf) {
		cout << buf << endl;
	}
	ShowStreamStateBit(is);	// badbit: 0 eofbit: 1 failbit: 1 goodbit: 0
	is.clear();
	ShowStreamStateBit(is);	// badbit: 0 eofbit: 0 failbit: 0 goodbit: 1
	// set eof bit, good bit will auto unset !!!
	is.clear(is.eofbit);
	ShowStreamStateBit(is);	// badbit: 0 eofbit: 1 failbit: 0 goodbit: 0
	is.clear(is.goodbit);
	ShowStreamStateBit(is);	// badbit: 0 eofbit: 0 failbit: 0 goodbit: 1
	is.setstate(is.eofbit);
	ShowStreamStateBit(is);	// badbit: 0 eofbit: 1 failbit: 0 goodbit: 0
	is.setstate(is.eofbit);
	ShowStreamStateBit(is);	// badbit: 0 eofbit: 1 failbit: 0 goodbit: 0
	is.setstate(is.goodbit);
	ShowStreamStateBit(is);	// badbit: 0 eofbit: 1 failbit: 0 goodbit: 0
	return is;
}

int main(int argc, char **argv)
{
	Read(cin);

	return 0;
}
