/* 2016.12.29 19:06
 * P_414
 * !!!
 * other operations of shared_ptr !!!
 * shared_ptr<T> p(q): 'q' is point to 'new' space; after copy, memory of 'q'
 *	will be in charged by 'p'
 * shared_ptr<T> p(u): 'u' is unique_ptr; after copy, 'u' will be empty
 * shared_ptr<T> p(q, d): 'p' take over 'q' and using 'd' replace 'delete'
 * p.reset():
 * p.reset(q):
 * p.reset(q, d):
 *	if 'p' is the only pointer point to shared_ptr, reset() whill release
 *	it then set 'p' to NULL(or set 'p' to 'q' if provided, as well as using
 *	'd' replace 'delete')
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void Process(shared_ptr<int> sptr)
{
	cout << sptr.use_count() << endl;
}
void Del1(int)
{
	cout << "del1" << endl;
}
void Del2(double)
{
	cout << "del2" << endl;
}
void Shared_ptrAndNewEG()
{
	// shared_ptr could be initialized using new !!!
	// shared_ptr<T>(new T) is explicit !!!
	//shared_ptr<int> p1 = new int(1024);	// invalid
	shared_ptr<int> p2(new int(1024));

	shared_ptr<int> sptr = make_shared<int>(3);
	// reset() will update reference count !!!
	sptr.reset();
	cout << sptr;
	// output: 0
	
	int *pI = new int;
	Process(shared_ptr<int>(pI));
	*pI = 1;
	// actually, 'pI' is already deleted after Process() !!!
	// never using a common-pointer to access smart pointer !!!

	pI = sptr.get();
	shared_ptr<int> sptr1(pI);
	/* using sptr.get() to initialize another shared_ptr is invalid
	 * although it can be compiled, because this will cause memory deleted
	 * twice
	 */

	// if 'sptr' is not the only user, copy it befor changing value
	if (sptr.unique() != true)
		sptr.reset(new int(*sptr));
	*sptr += 1;

	sptr.reset(new int(3), Del1);
}

int main(int argc, char **argv)
{
	shared_ptr<int> p(new int(42));
	Process(shared_ptr<int>(p));
	// output: 2

	return 0;
}

