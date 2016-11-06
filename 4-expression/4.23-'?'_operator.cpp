/* 2016.09.24 22:06
 * P_135
 */
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string s = "word";
	//std::string p1 = s + s[s.size() -1] == 's' ? "" : "s";
	std::string p1 = s + (s[s.size() -1] == 's' ? "" : "s");

	std::cout << p1;

	return 0;
}

