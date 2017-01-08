/* 2017.01.08 11:08
 * P_452
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>

using namespace std;

using line_no = vector<std::string>::size_type;
class QueryResult;
class TextQuery {
	public:
		TextQuery(ifstream&);
		QueryResult query(const string&) const;
	private:
		shared_ptr<vector<string>> file;
		map<string, shared_ptr<set<line_no>>> wm;
};
class QueryResult {
	friend ostream & print(ostream &, QueryResult const &);
	public:
		QueryResult(string s, shared_ptr<set<line_no>> p,
				shared_ptr<vector<string>> f):
			sought(s), lines(p), file(f) { }
		set<line_no>::const_iterator begin();
		set<line_no>::const_iterator end();
		shared_ptr<vector<string>> get_file();
	private:
		string sought;
		shared_ptr<set<line_no>> lines;
		shared_ptr<vector<string>> file;
};

int main(int argc, char **argv)
{

	return 0;
}

