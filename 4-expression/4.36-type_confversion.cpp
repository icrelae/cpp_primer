/* 2016.09.27 23:18
 * P_147
 * !!!
 * type convert explicitly: !!!
 * static_cast:
 *	using for all type with out const
 * const_cast:
 *	only for change const and only const_cast can change const
 *	assign const<char>(const char) is undefined behavior
 * reinterpret_cast:
 *	very dangerous, provide low level reinterpretation
 *	EG:	int *ip; char *cp = reinterpret_cast<char *>(ip);
 * dynamic_cast:
 *	support dynamic type realize, see chapter 19.2(P_730)
 */
#include <iostream>

int main(int argc, char **argv)
{
	int i = 3;
	double d = 2.5;


	std::cout << i * d << std::endl;			// 7.5
	std::cout << i * static_cast<int>(d) << std::endl;	// 6

	return 0;
}

