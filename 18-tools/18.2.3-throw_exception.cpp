/* 2017.04.10 20:44
 * P_687
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

struct  Foo {
	int *p;
	Foo(size_t size): p(new int[size]) {
	}
	~Foo() {
		delete []p;
	}
};

void exercise(int *b, int *e)
{
	vector<int> v(b, e);		// auto destruct
	int *p = new int[v.size()];	// memory leak
	// method 1
	struct Foo foo(v.size());
	// method 2
	shared_ptr<int> sp = make_shared<int>(v.size());
	ifstream in("ints");		// auto destruct
}

int main(int argc, char **argv)
{

	return 0;
}

