/* 2016.09.04 13:55
 * P_103
 */
#include <iostream>

std::string	sa[9];
int	ia[9];
int main(int argc, char **argv)
{
	std::string	sa2[9];
	int	ia2[9];

	for (int i = 0; i < 10; ++ i) {
		std::cout << ia[i] << ' ' << ia2[i] << std::endl;
		std::cout << sa[i] << std::endl;
		std::cout<< sa2[i] << std::endl;
	}

	return 0;
}

