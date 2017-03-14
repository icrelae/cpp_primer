/* 2017.03.14 19:40
 * P_583
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T, unsigned size>
constexpr unsigned sizeOf(const T (&arr)[size])
{
	return size;
}

int main(int argc, char **argv)
{
	int arrInt[] = {1, 2, 3, 4, 5};
	cout << sizeOf(arrInt);
	// output: 5

	return 0;
}

