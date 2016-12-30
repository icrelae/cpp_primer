/* 2016.12.30 10:11
 * P_420
 * !!!
 * shared_ptr have no release(): !!!
 *	shared_ptr cannot give away ownership unless it's unique() because the
 *	other copy will still destroy the object
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main(int argc, char **argv)
{
	shared_ptr<int> a = make_shared<int>(0);
	shared_ptr<int> b(a); // a.use_count() == b.use_count() == 2

	int *p = a.release(); // b will still call delete on it

	return 0;
}

