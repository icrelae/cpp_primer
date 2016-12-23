/* 2016.12.23 20:34
 * P_363
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

void Quiz1033(string const &inFile, string const &outFileOdd, string const &outFileEven)
{
	ifstream is(inFile);
	ofstream osOdd(outFileOdd), osEven(outFileEven);
	istream_iterator<int> itIstream(is), itEof;
	ostream_iterator<int> itOstreamOdd(osOdd, " "), itOstreamEven(osEven, "\n");
	while (itIstream != itEof) {
		if ((*itIstream % 2) == 0)
			*itOstreamEven++ = *itIstream;
		else
			*itOstreamOdd++ = *itIstream;
		++itIstream;
	}
}

int main(int argc, char **argv)
{
	Quiz1033("/tmp/input", "/tmp/outputOdd", "/tmp/outputEven");

	return 0;
}

