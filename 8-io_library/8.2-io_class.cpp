/* 2016.11.06 11:06
 * P_280
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

istream &ShowStreamStateBit(istream &is)
{
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
	ShowStreamStateBit(is);
	/* wrong way to get state bit */
	//cout << "badbit: " << is.badbit << ' ';
	//cout << "eofbit: " << is.eofbit << ' ';
	//cout << "failbit: " << is.failbit << ' ';
	//cout << "goodbit: " << is.goodbit << ' ';
	while (is >> buf) {
		cout << buf << endl;
	}
	ShowStreamStateBit(is);
	is.clear();
	// set eof bit, good bit will auto unset !!!
	is.clear(is.rdstate() | is.eofbit);
	ShowStreamStateBit(is);
	// unset eof bit, good bit will auto set !!!
	is.clear(is.rdstate() & ~is.eofbit);
	ShowStreamStateBit(is);
	return is;
}

int main(int argc, char **argv)
{
	Read(cin);

	return 0;
}

