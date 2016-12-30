/* 2016.12.30 10:11
 * P_419
 * !!!
 * operations of unique_ptr: !!!
 * unique_ptr<T> u1:
 * unique_ptr<T, D> u2: empty pointer, using type 'D' func to replace 'delete'
 * unique_ptr<T, D> u(d): empty pointer, using 'd'(type is 'D') to replace 'delete'
 * u = nullptr: release u
 * u.release(): return pointer, set u empty, obj won't be released !!!
 * u.reset(): release u
 * u.reset(q): q is a common ptr, make u taking charge on q
 * u.reset(nullptr): set u empty
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

unique_ptr<int> ExceptionOfNoCopy()
{
	unique_ptr<int> uptr(new int(0));
	return uptr;
}
void UniqueptrEG()
{
	unique_ptr<int> uptr(new int(0));
	// hand over object of uptr to uptr1
	unique_ptr<int> uptr1(uptr.release());
	unique_ptr<int> uptr2(new int(2));
	// uptr1 release object 'int(0)', take charge on 'int(2)'
	uptr1.reset(uptr2.release());

	// release() won't delete obj
	auto p = uptr1.release();
	delete p;

	// invalid, no copy, no assign
	unique_ptr<int> uptrInvalid(uptr);
	unique_ptr<int> uptrInvalid1;
	uptrInvalid1= uptr;
	// a valid exception for no copy of unique_ptr
	unique_ptr<int> uptrExcp = ExceptionOfNoCopy();
}

int main(int argc, char **argv)
{
	UniqueptrEG();

	return 0;
}

