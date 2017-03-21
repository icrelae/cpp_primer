/* 2017.03.21 20:11
 * P_612
 *
 * move elem to dest
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	for (size_t i = 0; i != 10; ++i)
		alloc.construct(dest++, std::move(*elem++));

	return 0;
}

