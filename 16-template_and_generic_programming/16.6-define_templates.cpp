/* 2017.03.14 19:40
 * P_583
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T, unsigned size>
T* my_begin(T (&arr)[size])
{
	return arr;
}

template<typename T, unsigned size>
T* my_end(T (&arr)[size])
{
	return (arr+size);
}

int main(int argc, char **argv)
{
	int arrInt[] = {1, 2, 3, 4, 5};
	for (auto x = my_begin(arrInt); x != my_end(arrInt); ++x)
		cout << *x << ' ';
	// output: 1 2 3 4 5 

	return 0;
}

