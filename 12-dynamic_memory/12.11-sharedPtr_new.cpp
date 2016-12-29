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
	shared_ptr<int> p(new int(42));
	Process(shared_ptr<int>(p.get()));
	// output: 1

	return 0;
}

