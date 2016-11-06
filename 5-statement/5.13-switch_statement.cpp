/* 2016.10.04 09:50
 * P_164
 * case in switch should be const int
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	// (a)
	unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
	char ch = next_text();
	switch (ch) {
		case 'a':
			aCnt ++;
			break;	// need break
		case 'e':
			eCnt ++;
			break;
		default:
			iouCnt ++;
			break;
	}

	// (b)
	unsigned index = some_value();
	switch (index) {
		case 1:
			int ix;	// crosses initialize
			ix = get_value();
			ivec[ix] = index;
			break;
		default:
			ix = ivec.size() - 1;
			ivec[ix] = index;
	}

	// (c)
	unsigned evenCnt = 0, oddCnt = 0;
	int digit = gt_num() % 10;
	switch (digit) {
		case 1: case 3: case 5: case 7: case 9:
			oddCnt ++;
			break;
		case 2: case 4: case 6: case 8: case 0:
			evenCnt ++;
			break;
	}

	// (d)
	const unsigned ival = 512, jval = 1024, kval = 4096;
	unsigned bufsize;
	unsigned swt = get_bufCnt();
	switch (swt) {
		// case should be const
		case ival:
			bufsize = ival * sizeof(int);
			break;
		case jval:
			bufsize = jval * sizeof(int);
			break;
		case kval:
			bufsize = kval * sizeof(int);
			break;
	}

	return 0;
}

