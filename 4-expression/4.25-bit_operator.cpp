/* 2016.09.25 11:45
 * P_139
 * !!!
 * 对带符号数执行位运算属于未定义行为	// !!!
 */
#include <iostream>
#include <iomanip>

int main(int argc, char **argv)
{
	char cq = 0x71 << 6;
	int iq = 0x71 << 6;

	std::cout << std::hex << (int)cq << ' ' << iq;	// 0x40 0x1c40

	return 0;
}

