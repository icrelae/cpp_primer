/* 2016.09.18 22:35
 * P_110
 * compare sting and compare cstring
 */
#include <iostream>

int Compare(const std::string stra, const std::string strb)
{
	signed char result = stra < strb ? -1 : 0;
	result = stra > strb ? 1 : result;
	return result;
}
int Compare(const char *stra, const char *strb)
{
	while (*stra != '\0' && *strb != '\0' && *stra == *strb) {
		++ stra;
		++ strb;
	}
	signed char result = *stra < *strb ? -1 : 0;
	result = *stra > *strb ? 1 : result;
	return result;
}
int main(int argc, char **argv)
{
	std::string stra = "abcdefg";
	std::string strb = "acdefgh";
	char ca[] = "abcdefg";
	char cb[] = "acdefgh";
	std::cout << Compare(stra, stra) << std::endl;
	std::cout << Compare(stra, strb) << std::endl;
	std::cout << Compare(strb, stra) << std::endl;
	std::cout << Compare(ca, ca) << std::endl;
	std::cout << Compare(ca, cb) << std::endl;
	std::cout << Compare(cb, ca) << std::endl;

	return 0;
}

