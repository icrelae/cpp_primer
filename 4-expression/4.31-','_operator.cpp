/* 2016.09.25 15:10
 * P_141
 * ???
 */
#include <iostream>
#include <vector>

void EG(std::vector<int> ivec)
{
	std::vector<int>::size_type cnt = ivec.size();

	for (std::vector<int>::size_type ix = 0;
			ix != ivec.size(); ++ix, --cnt)
		ivec[ix] = cnt;

	for (auto i : ivec)
		std::cout << i << ' ';
	std::cout << std::endl;
}

void EG_M(std::vector<int> ivec)
{
	std::vector<int>::size_type cnt = ivec.size();

	for (std::vector<int>::size_type ix = 0;
			ix != ivec.size(); ix++, cnt--)
		ivec[ix] = cnt;

	for (auto i : ivec)
		std::cout << i << ' ';
	std::cout << std::endl;
}
int main(int argc, char **argv)
{
	std::vector<int> ivec = {0, 1, 2, 3, 4};

	EG(ivec);	// output: 5 4 3 2 1
	EG_M(ivec);	// output: 5 4 3 2 1
	// nothing different ???

	return 0;
}

