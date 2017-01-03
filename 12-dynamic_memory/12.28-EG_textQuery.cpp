/* 2017.01.02 10:53
 * P_432
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>

using namespace std;

void ShowContent(shared_ptr<vector<string>> lines)
{
	for (auto const &line : *lines)
		cout << line << endl;
}
void ShowMap(map<string, set<unsigned>> wordToLines)
{
	for (auto const &pair : wordToLines) {
		cout << pair.first << ":";
		for (auto const &x : pair.second)
			cout << x << ' ';
		cout << endl;
	}
}
string erasePunc(string str)
{
	static set<char> punctuations{' ', ',', '.', ';'};
	for (auto itStr = str.begin(); itStr != str.end(); ++itStr) {
		if (punctuations.find(*itStr) != punctuations.end()) {
			itStr = str.erase(itStr) - 1;
		}
	}
	return str;
}
shared_ptr<vector<string>> getContent(istream &is)
{
	shared_ptr<vector<string>> lines = make_shared<vector<string>>();
	string line;
	while (getline(is, line)) {
		lines->push_back(line);
	}
	return lines;
}
map<string, set<unsigned>> getMap(shared_ptr<vector<string>> lines)
{
	map<string, set<unsigned>> wordToLines;
	for (vector<string>::size_type i = 0; i < lines->size(); ++i) {
		istringstream iss(lines->at(i));
		string word;
		while (iss >> word) {
			word = erasePunc(word);
			wordToLines[word].insert(i);
		}
	}
	return wordToLines;
}
void Query(string keyWord, shared_ptr<vector<string>> lines, map<string, set<unsigned>> wordToLines)
{
	if (wordToLines.count(keyWord) != 0) {
		for (auto const &x : wordToLines[keyWord]) {
			cout << x << ": " << lines->at(x) << endl;
		}
	}
}
void TextQuery(istream &is)
{
	shared_ptr<vector<string>> lines = getContent(is);
	map<string, set<unsigned>> wordToLines = getMap(lines);

	ShowContent(lines);
	ShowMap(wordToLines);
	while (true) {
		cout << "enter word to look for, 'q' to quit:";
		string str;
		if (!(cin >> str) || str == "q")
			break;
		Query(str, lines, wordToLines);
	}
}

int main(int argc, char **argv)
{
	ifstream ifs("/tmp/input");
	TextQuery(ifs);

	return 0;
}
/* /tmp/input:
 *	a b c
 *	a b
 *	a b c,
 * output:
 *	a b c
 *	a b
 *	a b c,
 *	a:0 1 2 
 *	b:0 1 2 
 *	c:0 2 
 *	enter word to look for, 'q' to quit:a
 *	0: a b c
 *	1: a b
 *	2: a b c,
 *	enter word to look for, 'q' to quit:b
 *	0: a b c
 *	1: a b
 *	2: a b c,
 *	enter word to look for, 'q' to quit:c
 *	0: a b c
 *	2: a b c,
 *	enter word to look for, 'q' to quit:d
 *	enter word to look for, 'q' to quit:q
 */

