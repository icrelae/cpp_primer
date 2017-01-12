/* 2017.01.12 08:39
 * P_472
 * !!!
 * 'std::move(var)': !!!
 * 1) head file: <utility>
 * 2) return rvalue of 'var'
 * 3) always using 'std::move' rather than 'move'
 * 4) you can assign or destruct var after move it, but you can't using the
 *	moved value of var any more
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void RvalueReferenceEG()
{
	int i = 1;
	int &r = i;
	//int &&rr = i;		// wrong
	//int &r2 = i * 2;	// wrong
	const int &r3 = i * 2;
	int &&rr2 = i * 2;
	//int &&rr3 = rr2;	// wrong: variables are lvalue
	int &r4 = ++i;
	int &&rr4 = i++;
}

int main(int argc, char **argv)
{

	return 0;
}

