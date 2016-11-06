/* 2016.08.28 14:39
 * P_94
 * read a word from cin then stored into vector, 
 * toupper and print them into a line each word.
 */
#include <iostream>
#include <vector>

using std::vector;
using std::string;

int main(int argc, char **argv)
{
	vector<string> vec;
	string str;
	while (std::cin >> str) {
		for (auto &i : str)
			i = toupper(i);
		vec.push_back(str);
		std::cout << vec.back() << std::endl;
	}

	return 0;
}
