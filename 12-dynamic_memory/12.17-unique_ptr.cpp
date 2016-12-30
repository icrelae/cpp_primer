/* 2016.12.30 10:11
 * P_419
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main(int argc, char **argv)
{
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;

	// invalid, no match for 'unique_ptr<int>(int)'
	IntP p0(ix);

	// invalid, uptr p1 will try to delete viariable in stack
	IntP p1(pi);

	// vaild, uptr p2 take charge on pi2
	IntP p2(pi2);

	// invalid, uptr p3 will try to delete viariable in stack
	IntP p3(&ix);

	// valid
	IntP p4(new int(2048));

	// invaid, delete pi2 twice(p5 and p2 take charge on single obj)
	IntP p5(p2.get());

	return 0;
}

