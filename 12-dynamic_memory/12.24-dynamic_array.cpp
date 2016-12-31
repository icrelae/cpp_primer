/* 2016.12.31 16:26
 * P_426
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main(int argc, char **argv)
{
	string cstra = "asd";
	string cstrb = "fgh";
	unique_ptr<char []> uptr(new char[sizeof(cstra) + sizeof(cstrb) - 1]);
	size_t iUptr= 0;
	for (auto const &c : cstra) {
		uptr[iUptr++] = c;
	}
	iUptr = cstra.size();
	for (auto const &c : cstrb)
		uptr[iUptr++] = c;
	uptr[iUptr] = '\0';
	string str(uptr.get());
	cout << str;
	// output: asdfgh

	return 0;
}

