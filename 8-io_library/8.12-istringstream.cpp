/* 2016.11.13 20:42
 * P_289
 * ???
 * why not initialize in class ???
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo
{
	string name;
	vector<string> phones;
};
int main(int argc, char **argv)
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(cin, line)) {
		PersonInfo info;
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
		record.clear();
	}

	return 0;
}
