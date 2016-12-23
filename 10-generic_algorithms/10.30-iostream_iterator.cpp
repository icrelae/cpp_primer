/* 2016.12.23 08:22
 * P_362
 */
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	istream_iterator<int> itIstream(cin), itEof;
	vector<int> vecInt;
	copy(itIstream, itEof, back_inserter(vecInt));
	sort(vecInt.begin(), vecInt.end());
	copy(vecInt.begin(), vecInt.end(), ostream_iterator<int>(cout));

	return 0;
}

