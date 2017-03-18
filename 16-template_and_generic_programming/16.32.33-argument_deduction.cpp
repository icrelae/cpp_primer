/* 2017.03.18 14:30
 * P_603
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
bool compare1(const T a, const T b)
{
	return a > b;
}
template<typename T, typename U>
bool compare2(const T a, const U b)
{
	return a > b;
}
template<typename T>
void show(ostream &os, const T obj)
{
	os << obj << endl;
}

int main(int argc, char **argv)
{
	long l = 1;
	//compare1(l, 3); // invalid, 3 -> int
	compare2(l, 3);
	show(cout, l);

	return 0;
}

