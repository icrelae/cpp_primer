/* 2017.02.09 22:14
 * P_507
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Foo {
	public:
		Foo(int x): data(x) { }
		bool operator()(int x)
		{
			return x == data;
		}
	private:
		int data;
};

int main(int argc, char **argv)
{
	vector<int> vecInt{1, 2, 3, 1, 2, 3};
	replace_if(vecInt.begin(), vecInt.end(), Foo(2), 0);
	for (int x : vecInt)
		cout << x << ' ';
	// output: 1 0 3 1 0 3 

	return 0;
}

