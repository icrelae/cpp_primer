/* 2016.11.24 21:41
 * P_320
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void FillVector(vector<int> &vec)
{
	cout << vec.capacity() << endl;
	for (auto size = vec.capacity(); size > 0; --size)
		vec.push_back(0);
}
int main(int argc, char **argv)
{
	vector<int> vec{0};
	FillVector(vec);
	FillVector(vec);
	FillVector(vec);
	FillVector(vec);
	FillVector(vec);
	FillVector(vec);
	// output: 1 2 4 8 16 32

	return 0;
}

