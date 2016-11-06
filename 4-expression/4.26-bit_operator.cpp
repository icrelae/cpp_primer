/* 2016.09.25 11:45
 * P_139
 * !!!
 * 对带符号数执行位运算属于未定义行为	// !!!
 */
#include <iostream>
#include <iomanip>

int main(int argc, char **argv)
{
	unsigned int quiz= 0;

	quiz |= 1UL << 26;	// book error!!!
	std::cout.flags(std::ios_base::hex);
	std::cout << quiz;;	// output: 4000000

	return 0;
}

