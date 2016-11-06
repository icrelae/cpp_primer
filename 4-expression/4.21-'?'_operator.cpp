/* 2016.09.24 21:22
 * P_135
 * double odd number in vector suing '?' operator
 */
#include <iostream>
#include <vector>

void Method1()
{
	std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7};

	for (auto p = vec.begin(); p < vec.end(); ++p) {
		*p = (*p % 2) == 1 ? *p << 1 : *p;
		std::cout << *p << ' ';
	}
}
int main(int argc, char **argv)
{
	Method1();

	return 0;
}

