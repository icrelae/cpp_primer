/* 2017.04.08 19:50
 * P_676
 * single byte operate: !!!
 * is.get(ch)		// read next byte into 'ch' from 'istream is', return 'is'
 * os.put(ch)		// output 'ch' to 'ostream os', return 'os'
 * is.get()		// return next byte as 'int'
 * is.putback(ch)	// put 'ch'(have to be same with last byte) back into 'is', return is
 * is.unget()		// put last byte back into 'is', return 'is'
 * is.peek()		// return next byte as 'int', won't delete it
 * multi-byte operate: !!!
 * is.get(sink, size, delim)
 *			// read into 'sink' at most 'size' byte, or meet
 *			// 'delim', in that case leave 'delim' in stream
 * is.getline(sink, size, delim)
 *			// read and drop 'delim'
 * is.read(sink, size)	// return 'is'
 * is.gcount()		// return byte number of last unformatted read
 * os.write(source, size)
 *			// write 'size' byte of 'source' into 'os', return 'os'
 * is.ignore(size=1, delim='EOF')
 *			// read and ignore
 *			// EOF: end of file, header: <cstdio>
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

void UnformattedIOEG()
{
	char c;
	/* invalid
	 * 'cin.get()' cast 'char' into 'unsigned char' then return 'int'
	 * because it can indicate 'EOF' which is a negative, 'char' have no
	 * usable value for this
	 */
	while ((c = cin.get()) != EOF)
		cout.put(c);
}

int main(int argc, char **argv)
{
	ifstream is("/tmp/tmp.txt");
	char cstr[128];
	size_t i = 0;
	// if length of a line over '5', 'is.good()' will be 'false'
	while (is.getline(cstr, 5, '\n')) {
		cout << ++i << ": " << cstr << endl;
	}

	return 0;
}
/* /tmp/tmp.txt:
 *	1
 *	12
 *	
 *	123
 *	1234
 *	12345
 *	123456
 *	1234567
 * output:
 *	1: 1
 *	2: 12
 *	3: 
 *	4: 123
 *	5: 1234
 */

