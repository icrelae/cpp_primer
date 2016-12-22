/* 2016.12.22 19:39
 * P_362
 * !!!
 * ???
 * operators of istream_iterator: !!!
 *	istream_iterator<T> in(iStream)
 * 	istream_iterator<T> end
 * 	in1 == in2
 * 	in1 != in2
 * 	*in: return value of istream
 * 	in->mem: equals to (*in).mem
 * 	++in, in++
 * reading data from stream will happening befor first using '*in', so be
 *	careful on destructor an unused is_it and reading a stream synchronously
 *
 * operators of ostream_iterator: !!!
 * ostream_iterator<T> out(oStream)
 * ostream_iterator<T> out(oStream, delim):
 *	output tails delim(array of char ending with '\0')
 * out = val: equals to 'oStream << val'
 * *out, ++out, out++: do nothing but return out
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <iterator>
#include <algorithm>

using namespace std;

void IStreamIteratorEG()
{
	istream_iterator<int> itIstreamInt(cin);
	istream_iterator<int> eof;
	while (itIstreamInt != eof)
		cout << *itIstreamInt++;
	vector<int> vecInt(itIstreamInt, eof);

	istream_iterator<int> itIstreamInt1(cin);
	//cout << accumulate(itIstreamInt1, eof, 0);
	back_inserter(vecInt) = *itIstreamInt1;
}
void OStreamIteratorEG()
{
	vector<int> vecInt({1, 2, 3, 4, 5, 6});
	ostream_iterator<int> itOstreamInt(cout, " ");
	for (auto const num : vecInt) {
		*itOstreamInt++ = num;
		//equals to 'itOstreamInt = num' !!!
	}
	copy(vecInt.cbegin(), vecInt.cend(), itOstreamInt);
	// output: 1 2 3 4 5 6 1 2 3 4 5 6 
}

int main(int argc, char **argv)
{
	vector<string> vecStr;
	string fileName("/etc/issue");
	ifstream is(fileName);
	istream_iterator<string> itIstream(is);
	//istream_iterator<string> itIstream(ifstream(fileName));	// 1)
	istream_iterator<string> itEof;
	ostream_iterator<string> itOstream(cout, " ");
	copy(itIstream, itEof, back_inserter(vecStr));			// 2)
	copy(vecStr.cbegin(), vecStr.cend(), itOstream);

	/* 2) will be invalid due to 1), y ???
	 * besides that, 'itIstream != itEof' will also be invalid
	 */

	return 0;
}

