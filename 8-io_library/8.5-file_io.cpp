/* 2016.11.07 22:26
 * P_285
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<string> vec;
	ifstream ifs("/etc/bash.bashrc");
	for (vector<string>::size_type i = 0; ifs.good() == 1; ++i) {
		string line;
		ifs >> line;
		vec.push_back(line);
		cout << '#' << vec[i] << '#' << endl;
	}
	ifs.close();

	return 0;
}
