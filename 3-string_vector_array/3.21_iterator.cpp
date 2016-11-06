/* 2016.08.28 16:34
 * P_99
 * iterator:
 *  vec.end() returns next address of last element where is not a object, so it
 *  cannot moved using ++ or smt
 */
#include <iostream>
#include <string>
#include <vector>

using std::vector;

void EG108() 
{
	std::string str;
	/* std::string::iterator str_it = str.begin();
	 * if get str.begin befor getline, result will be unpredictable
	 */
	getline(std::cin, str);
	std::string::iterator str_it = str.begin();

	for (auto it = str_it; it != str.end() && !isspace(*it); ++ it) {
		*it = toupper(*it);
	}
	std::cout << str << std::endl;
}

int main(int argc, char **argv)
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{10};
	vector<int> v5{10, 42};
	vector<int> v6{10};
	vector<vector<int>> vi = {v1, v2, v3, v4, v5, v6};
	vector<std::string> v7{10, "hi"};

	vector<vector<int>>::size_type i_vi;
	for (auto &i : vi) {
		std::cout << i.size() << std::endl;
		for (auto &j : i)
			std::cout << j << ' ';
		std::cout << std::endl;
	}

	return 0;
}

