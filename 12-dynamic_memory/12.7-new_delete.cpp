/* 2016.12.29 19:06
 * P_411
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void NewEG()
{
	const string *pStr = new const string;
	delete pStr;
	// by default, if 'new' failed, throw 'std::bad_alloc'
	// here indicate do not throw exception, just return 'NULL'
	int *pI = new(nothrow) int;
	delete pI;
}

void Show(shared_ptr<vector<int>> vecIntPtr)
{
	for (auto const &x : *vecIntPtr)
		cout << x << ' ';
	cout << endl;
}
void Input(shared_ptr<vector<int>> vecIntPtr)
{
	int arrInt[] = {1, 2, 3, 4, 5};
	vecIntPtr->insert(vecIntPtr->begin(), begin(arrInt), end(arrInt));
}
int main(int argc, char **argv)
{
	shared_ptr<vector<int>> vecIntSptr = make_shared<vector<int>>();
	Input(vecIntSptr);
	Show(vecIntSptr);
	// output: 1 2 3 4 5 

	return 0;
}

