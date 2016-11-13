/* 2016.11.13 20:57
 * P_289
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

vector<PersonInfo> ReadInfo(istream &is)
{
	string line, word;
	vector<PersonInfo> people;
	while (getline(is, line)) {
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	return people;
}

bool Valid(const string &number)
{
	return number.size() == 11 ? true : false;
}
string Format(string number)
{
	number.insert(3, " ");
	number.insert(8, " ");
	return number;
}
void ShowInfo(vector<PersonInfo> people)
{
	for (const auto &entry : people) {
		ostringstream formatted, badNums;
		for (const auto &nums : entry.phones) {
			if (!Valid(nums)) {
				badNums << ' ' << nums;
			} else
				formatted << ' ' << Format(nums);
		}
		if (badNums.str().empty())
			cout << entry.name << ' '
				<< formatted.str() << endl;
		else
			cerr << "input error: " << entry.name
				<< "invalid number(s) " << badNums.str() << endl;
	}
}

int main(int argc, char **argv)
{
	ifstream ifs("/tmp/input.txt");
	ShowInfo(ReadInfo(ifs));

	return 0;
}

/* /tmp/input.txt: 
 * aaa 12345678901
 * bbb 12345678901 22345678901 32345678901
 * ccc 12345678901 22345678901 3234567890
 * ddd 12345678901 22345678901 323456789012
 * eee 123
 */

