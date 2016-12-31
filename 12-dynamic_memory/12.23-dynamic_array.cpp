/* 2016.12.31 16:26
 * P_426
 * !!!
 * dynamic arrays: !!!
 * unavailable for begin()|end()
 * unique_ptr could manage dynamic array:
 *	unique_ptr<T[]> u
 *	unique_ptr<T[]> u(p)
 *	u[i]
 * uptr will call 'delete[] p' to destruct, but sptr won't,
 * so sptr have to define deleter to manage dynamic array:
 *	sptr<int> sp(new int[10], [] (int *p) { delete [] p;});
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main(int argc, char **argv)
{
	char cstra[] = "asd";
	char cstrb[] = "fgh";
	unique_ptr<char []> uptr(new char[sizeof(cstra) + sizeof(cstrb) - 1]);
	size_t iUptr= 0;
	for (auto const &c : cstra)
		uptr[iUptr++] = c;
	iUptr = sizeof(cstra) - 1;
	for (auto const &c : cstrb)
		uptr[iUptr++] = c;
	string str(uptr.get());
	cout << str;
	// output: asdfgh

	return 0;
}

