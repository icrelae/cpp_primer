/* 2017.03.29 08:47
 * P_638
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <tuple>

using namespace std;

class QueryResult {
	public:
		QueryResult(vector<shared_ptr<string>> vecLines,
				shared_ptr<set<unsigned>> setNumbers):
			lines(vecLines), numbers(setNumbers) { }
		void printResult(ostream &os);
	private:
		vector<shared_ptr<string>> lines;
		shared_ptr<set<unsigned>> numbers;
};
void QueryResult::printResult(ostream &os)
{
	decltype(lines)::size_type i = 0;
	if (numbers != NULL)
		for (auto const &x : *numbers)
			os << x << ": " << *lines[i++] << endl;
}

class TextQuery {
	public:
		TextQuery(istream &is);
		//QueryResult query(string keyWord);
		tuple<vector<shared_ptr<string>>, shared_ptr<set<unsigned>>>
			query(string keyWord);
		void show();
	private:
		unsigned getContent(istream &is);
		unsigned getMap();
		string erasePunc(string str);
		vector<shared_ptr<string>> content;
		map<string, shared_ptr<set<unsigned>>> wordToLine;
};
TextQuery::TextQuery(istream &is)
{
	getContent(is);
	getMap();
}
//QueryResult TextQuery::query(string keyWord)
tuple<vector<shared_ptr<string>>, shared_ptr<set<unsigned>>> TextQuery::query(string keyWord)
{
	vector<shared_ptr<string>> lines;
	shared_ptr<set<unsigned>> numbers = NULL;
	if (wordToLine.count(keyWord) != 0) {
		numbers = wordToLine[keyWord];
		for (auto const &x : *numbers)
			lines.push_back(content[x]);
	}
	//QueryResult result(lines, numbers);
	tuple<vector<shared_ptr<string>>, shared_ptr<set<unsigned>>>
		result(lines, numbers);
	return result;
}
void TextQuery::show()
{
	for (auto const &line : content)
		cout << *line << endl;
	for (auto const &pair : wordToLine) {
		cout << pair.first << ":";
		for (auto const &x : *pair.second)
			cout << x << ' ';
		cout << endl;
	}
}
unsigned TextQuery::getContent(istream &is)
{
	string line;
	while (getline(is, line)) {
		shared_ptr<string> sptr = make_shared<string>(line);
		content.push_back(sptr);
	}
	return content.size();
}
unsigned TextQuery::getMap()
{
	for (decltype(content)::size_type i = 0; i < content.size(); ++i) {
		istringstream iss(*content[i]);
		string word;
		while (iss >> word) {
			word = erasePunc(word);
			if (wordToLine.count(word) == 0)
				wordToLine[word] = make_shared<set<unsigned>>();
			wordToLine[word]->insert(i);
		}
	}
	return wordToLine.size();
}
string TextQuery::erasePunc(string str)
{
	static set<char> punctuations{' ', ',', '.', ';'};
	for (auto itStr = str.begin(); itStr != str.end(); ++itStr) {
		if (punctuations.find(*itStr) != punctuations.end()) {
			itStr = str.erase(itStr) - 1;
		}
	}
	return str;
}

void RunQueries(ifstream &infile)
{
	TextQuery tq(infile);
	tq.show();
	while (true) {
		cout << "enter word to look for, 'q' to quit:";
		string str;
		if (!(cin >> str) || str == "q")
			break;
		//QueryResult result = tq.query(str);
		//result.printResult(cout);
		tuple<vector<shared_ptr<string>>, shared_ptr<set<unsigned>>> result = tq.query(str);
		tuple_element<0, decltype(result)>::type lines = get<0>(result);
		tuple_element<1, decltype(result)>::type numbers = get<1>(result);
		decltype(lines)::size_type i = 0;
		if (numbers != NULL)
			for (auto const &x : *numbers)
				cout << x << ": " << *lines[i++] << endl;
	}
}

int main(int argc, char **argv)
{
	ifstream ifs("/tmp/input");
	RunQueries(ifs);

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

