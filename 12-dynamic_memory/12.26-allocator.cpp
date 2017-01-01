/* 2016.12.31 16:26
 * P_430
 * !!!
 * allocator: !!!
 *	head file: <memory>
 * operations for allocator: !!!
 *	allocator<T> a
 *	a.allocate(n): allocate space for n T without instruction
 *	a.deallocate(p, n):
 *		'p' have to be pointer returned by allocate()
 *		'n' have to be the number of allocate()
 *		user have to destroy every member of p befor deallocate()
 *	a.coustruct(p, args):
 *		'p' have to be a pointer typed 'T*', point to raw memory
 *	a.destroy(p):
 *		'p' is a pointer typed 'T*'
 * algorithm for allocator(defined in <memory>): !!!
 *	all return 'T*' point to memory after last element;
 *	uninitialized_copy(itBeg, itEnd, ptrBeg2):
 *		'ptrBeg2' point to raw memory and have to be big enough
 *	uninitialized_copy_n(itBeg, n, ptrBeg2):
 *		copy n elements to ptrBeg2
 *	uninitialized_fill(itBeg, itEnd, target):
 *		create objs in the range, value is target
 *	uninitialized_fill_n(itBeg, n, target):
 *		create n objs, value is target
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void AllocatorEG()
{
	allocator<string> alctStr;
	string *pStr = alctStr.allocate(20);
	auto pStr1 = pStr;
	alctStr.construct(pStr1++);		// ""
	alctStr.construct(pStr1++, 4, 'c');	// "cccc"
	alctStr.construct(pStr1++, "hi");	// "hi"
	while (pStr1 != pStr) {
		cout << *(pStr1-1) << ' ';
		alctStr.destroy(--pStr1);
	}
	alctStr.deallocate(pStr, 20);
	cout << endl;

	vector<int> vecInt{1, 2, 3, 4, 5};
	allocator<int> alctInt;
	int *pI = alctInt.allocate(vecInt.size() * 2);
	int* pI1 = uninitialized_copy(vecInt.begin(), vecInt.end(), pI);
	pI1 = uninitialized_fill_n(pI1, vecInt.size(), -1);
	while (pI1 != pI) {
		cout << *(pI1-1) << ' ';
		alctInt.destroy(--pI1);
	}
	alctInt.deallocate(pI, vecInt.size() * 2);
	cout << endl;
	/* output:
	 * hi cccc  
	 * -1 -1 -1 -1 -1 5 4 3 2 1 
	 */
}

int main(int argc, char **argv)
{
	AllocatorEG();

	allocator<string> alctStr;
	string str;
	size_t const size = 10;
	string *pStr = alctStr.allocate(size);
	string *pStrIdx = pStr;
	while (cin >> str && pStrIdx != (pStr+2)) {
		alctStr.construct(pStrIdx++, str);
	}
	while (cin >> str && pStrIdx != (pStr+10)) {
		uninitialized_fill_n(pStrIdx++, 1, str);
	}
	while (pStrIdx != pStr) {
		cout << *(pStrIdx-1) << ' ';
		alctStr.destroy(--pStrIdx);
	}
	alctStr.deallocate(pStr, size);
	/* input:	a b c d e f g
	 * output:	g f e d b a
	 * lost 'c' because it be readed but not constructed after last
	 *	loop in first 'while'
	 */

	return 0;
}

