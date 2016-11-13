/* 2016.11.13 11:10
 * P_289
 * !!!
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void ShowByWord(vector<string> strVec)
{
	istringstream iss;
	for (auto str : strVec) {
		iss.str(str);
		string word;
		while (iss >> word)
			cout << word << endl;
		// clear state bit of stream before next loop !!!
		iss.clear();
	}
}

vector<string> GetFileContent(string filePath)
{
	vector<string> fileContent;
	ifstream ifs(filePath);
	string line;
	while (getline(ifs, line))
		fileContent.push_back(line);
	ifs.close();
	return fileContent;
}
int main(int argc, char **argv)
{
	ShowByWord(GetFileContent("/etc/bash.bashrc"));

	return 0;
}
