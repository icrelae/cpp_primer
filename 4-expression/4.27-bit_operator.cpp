/* 2016.09.25 11:45
 * P_139
 * !!!
 * 对带符号数执行位运算属于未定义行为	// !!!
 */
#include <iostream>
#include <iomanip>

int main(int argc, char **argv)
{
	unsigned long ul1 = 3, ul2 = 7;
	std::cout.flags(std::ios_base::hex);
	
	std::cout << (ul1 & ul2) << " = " << 0x3 << std::endl;
	std::cout << (ul1 | ul2) << " = " << 0x7 << std::endl;
	std::cout << (ul1 && ul2) << " = " << true << std::endl;
	std::cout << (ul1 || ul2) << " = " << true << std::endl;

	return 0;
}
