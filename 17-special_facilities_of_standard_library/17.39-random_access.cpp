/* 2017.04.10 18:55
 * P_679
 * !!!
 * random access stream: !!!
 * // g: get, for instream
 * // p: put, for outstream
 * tellg()		// return current position for istream
 * tellp()		// return type: 'pos_type'
 * seekg(pos)
 * seekp(pos)		// set current position with 'pos'
 * seekg(off, from)
 * seekp(off, from)	// set current position after or before 'off' of 'from'
 *			// 'from' can be one of: 'beg', 'cur', 'end'
 *			// 'off' can be negative
 *
 * for fstream or stringstream, read and write share a single 'current ops' !!!
 * so reset 'current pos' is necessary when switch between read and write
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	fstream file("/tmp/tmp.txt", fstream::ate| fstream::in| fstream::out);
	if (!file) {
		cerr << "unable to open file!" << endl;
		return EXIT_FAILURE;
	}
	// open file with 'ate', 'current pos' already at the end !!!
	fstream::pos_type fileEndPos = file.tellp();
	file.seekg(0, fstream::beg);
	size_t length = 0;
	string line;
	while (file && file.tellg() != fileEndPos && getline(file, line)) {
		// add '\n'
		length += line.size() + 1;
		fstream::pos_type currentPos = file.tellg();
		//file.seekp(fstream::end);	// wong, 'end=2', equal to 'seekp(2)'
		file.seekp(0, fstream::end);
		file << length;
		if (currentPos != fileEndPos)
			file << ' ';
		file.seekg(currentPos);
	}


	return 0;
}
/* /tmp/tmp.txt:
 *	abcd
 *	efg
 *	hi
 *	j
 * output(/tmp/tmp.txt):
 *	abcd
 *	efg
 *	hi
 *	j
 *	5 9 12 14
 */
