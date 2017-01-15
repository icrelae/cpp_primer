/* 2016.11.13 11:10
 * P_289
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

istream &ShowStreamStateBit(istream &is)
{
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
	while (is >> buf) {
		cout << buf << endl;
	}
	ShowStreamStateBit(is);
	is.clear();
	is.clear(is.rdstate() | is.eofbit);
	ShowStreamStateBit(is);
	is.clear(is.rdstate() & ~is.eofbit);
	ShowStreamStateBit(is);
	return is;
}

int main(int argc, char **argv)
{
	string str = "asdfg hjkl;";
	istringstream iss(str);
	Read(iss);
	/* output:
	 *	badbit: 0 eofbit: 0 failbit: 0 goodbit: 1 
	 *	asdfg
	 *	hjkl;
	 *	badbit: 0 eofbit: 1 failbit: 1 goodbit: 0 
	 *	badbit: 0 eofbit: 1 failbit: 0 goodbit: 0 
	 *	badbit: 0 eofbit: 0 failbit: 0 goodbit: 1 
	 */

	return 0;
}
