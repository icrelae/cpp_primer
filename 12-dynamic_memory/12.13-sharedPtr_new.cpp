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
	auto sp = make_shared<int>();
	auto p = sp.get();
	delete p;
	// delete twice

	return 0;
}

