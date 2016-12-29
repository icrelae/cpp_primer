/* 2016.12.29 19:06
 * P_415
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

int main(int argc, char **argv)
{
	auto p = new int();
	auto sp = make_shared<int>();

	Process(sp);
	// valid, sptr=sp, reference count ++

	Process(new int());
	// invalid, sptr=new int(), copy-construction is explicit

	Process(p);
	// invalid, sptr=(int *)p, no match for this convert

	Process(shared_ptr<int>(p));
	// valid, sptr=shared_ptr<int>(p), sptr take charge of p

	return 0;
}

