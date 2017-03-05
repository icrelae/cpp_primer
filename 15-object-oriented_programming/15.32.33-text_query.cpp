/* 2017.03.04 22:11
 * P_568
 *
 * ???
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <map>

using namespace std;


class QueryResult;
class TextQuery {
	public:
		using line_no = vector<std::string>::size_type;
		TextQuery(ifstream&);
		QueryResult query(const string&) const;
	private:
		shared_ptr<vector<string>> file;
		map<string, shared_ptr<set<line_no>>> wm;
};
TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (lines == NULL)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}
// totally as a result genarated by TextQuery::query()
class QueryResult {
	private:
		friend ostream & print(ostream &, QueryResult const &);
	public:
		using line_no = TextQuery::line_no;
		QueryResult(string s,
				shared_ptr<set<line_no>> p,
				shared_ptr<vector<string>> f):
			sought(s), lines(p), file(f) {
		}
		set<line_no>::const_iterator begin() {
			return lines->begin();
		}
		set<line_no>::const_iterator end() {
			return lines->end();
		}
		shared_ptr<vector<string>> get_file() {
			return file;
		}
	private:
		string sought;
		shared_ptr<set<line_no>> lines;
		shared_ptr<vector<string>> file;
};
// TextQuery::query() have to be defined after the defination of Query_base
QueryResult TextQuery::query(string const &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	// here 'loc' is a pair of '{string, shared_ptr<set<line_no>>}'
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}
ostream & print(ostream &os, QueryResult const &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << ' ';
	os << qr.lines->size() << "times" << endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ") ";
		os << *(qr.file->begin() + num) << endl;
	}
	return os;

}

class Query;
class Query_base {
	protected:
		using line_no = TextQuery::line_no;
		// protected destructor, only friend-class Query can using this class !!!
		virtual ~Query_base() = default;
	private:
		friend class Query;
		virtual QueryResult eval(const TextQuery&) const = 0;
		virtual string rep() const = 0;
};
class Query {
	private:
		friend Query operator~(const Query&);
		friend Query operator|(const Query&, const Query&);
		friend Query operator&(const Query&, const Query&);
	public:
		Query(const string&);
		QueryResult eval(const TextQuery &t) const {
			return q->eval(t);
		}
		string rep() const {
			return q->rep();
		}
	private:
		Query(shared_ptr<Query_base> query): q(query) {
		}
		shared_ptr<Query_base> q;
};
ostream& operator <<(ostream &os, const Query &query)
{
	return os << query.rep();
}

int main(int argc, char **argv)
{

	return 0;
}

