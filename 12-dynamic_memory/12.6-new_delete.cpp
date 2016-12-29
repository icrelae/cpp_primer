/* 2016.12.29 19:06
 * P_411
 */
#include <iostream>
#include <string>
#include <vector>

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

void Show(vector<int> *vecIntPtr)
{
	for (auto const &x : *vecIntPtr)
		cout << x << ' ';
	cout << endl;
}
void Input(vector<int> *vecIntPtr)
{
	int arrInt[] = {1, 2, 3, 4, 5};
	vecIntPtr->insert(vecIntPtr->end(), begin(arrInt), end(arrInt));
}
int main(int argc, char **argv)
{
	vector<int> *vecIntPtr = new vector<int>;
	Input(vecIntPtr);
	Show(vecIntPtr);
	delete vecIntPtr;
	// output: 1 2 3 4 5 

	return 0;
}

