/* 2017.03.04 22:11
 * P_574
 * !!!
 * set_intersection(	// insert intersection of a&b into set !!!
 *	a.begin(), a.end(),
 *	b.begin(), b.end(),
 *	inserter(set, set.begin()));
 * header: <algorithm>
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <algorithm>

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
		void show(ostream &os) {
			os << sought << endl;
			for (auto x : *lines) {
				os << x << ": ";
				os << file->at(x) << endl;
			}
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

/* !!!
 * Query_base
 *	WordQuery
 *	NotQuery{Query}
 *	BinaryQuery{Query lhs, rhs}
 *		AndQuery
 *		OrQuery
 * Query{WordQuery}
 */
class Query;
class Query_base {
	protected:
		using line_no = TextQuery::line_no;
		/* protected destructor !!!
		 * only derived-class and derived-class can using this class
		 */
		virtual ~Query_base() = default;
	private:
		friend class Query;
		virtual QueryResult eval(const TextQuery&) const = 0;
		virtual string rep() const = 0;
};
class WordQuery: public Query_base {
	private:
		// only Query can access this class !!!
		friend class Query;
		WordQuery(const string &s): query_word(s) {
		}
		QueryResult eval(const TextQuery &t) const {
			// here's returning (seekStr, setOfLines, fileContent)
			return t.query(query_word);
		}
		string rep() const {
			return query_word;
		}
		string query_word;
};
class Query {
	private:
		friend Query operator~(const Query&);
		friend Query operator|(const Query&, const Query&);
		friend Query operator&(const Query&, const Query&);
	public:
		Query(const string &s): q(new WordQuery(s)) {
		}
		QueryResult eval(const TextQuery &t) const {
			// here's 'q' can be AndQuery, OrQuery or WordQuery !!!
			return q->eval(t);
		}
		string rep() const {
			return q->rep();
		}
	private:
		// all friend operator(~|&) will call this constructor !!!
		Query(shared_ptr<Query_base> query): q(query) {
		}
		shared_ptr<Query_base> q;
};
ostream& operator <<(ostream &os, const Query &query)
{
	return os << query.rep();
}
class NotQuery: public Query_base {
	private:
		friend Query operator ~(const Query&);
		NotQuery(const Query &q): query(q) {
		}
		string rep() const {
			return "~(" + query.rep() + ")";
		}
		QueryResult eval(const TextQuery &text) const {
			QueryResult result = query.eval(text);
			shared_ptr<set<line_no>> ret_lines =
				make_shared<set<line_no>>();
			auto beg = result.begin(), end = result.end();
			auto size = result.get_file()->size();
			// insert !(result.lines) of result.file
			for (size_t n = 0; n != size; ++n) {
				if (beg == end || *beg != n)
					ret_lines->insert(n);
				else if (beg != end)
					++beg;
			}
			return QueryResult(rep(), ret_lines, result.get_file());
		};
		Query query;
};
Query operator ~(const Query &operand)
{
	// here will call private constructor of Query !!!
	return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery: public Query_base {
	protected:
		BinaryQuery(const Query &l, const Query &r, string s):
			lhs(l), rhs(r), opSym(s) {
		}
		string rep() const override {
			return "(" + lhs.rep() + " "
				+ opSym + " "
				+ rhs.rep() + ")";
		}
		Query lhs, rhs;
		string opSym;
};
class AndQuery: public BinaryQuery {
	private:
		friend Query operator &(const Query&, const Query&);
		AndQuery(const Query &l, const Query &r):
			BinaryQuery(l, r, "&") {
		}
		QueryResult eval(const TextQuery &text) const {
			QueryResult left = lhs.eval(text);
			QueryResult right = rhs.eval(text);
			shared_ptr<set<line_no>> ret_lines =
				make_shared<set<line_no>>();
			set_intersection(
					left.begin(), left.end(),
					right.begin(), right.end(),
					inserter(*ret_lines, ret_lines->begin()));
			return QueryResult(rep(), ret_lines, left.get_file());
		}
};
Query operator &(const Query &lhs, const Query &rhs)
{
	// here will call private constructor of Query !!!
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
class OrQuery: public BinaryQuery {
	private:
		friend Query operator |(const Query&, const Query&);
		OrQuery(const Query &l, const Query &r):
			BinaryQuery(l, r, "|") {
		}
		QueryResult eval(const TextQuery &text) const {
			QueryResult left = lhs.eval(text);
			QueryResult right = rhs.eval(text);
			shared_ptr<set<line_no>> ret_lines =
				make_shared<set<line_no>>(left.begin(), left.end());
			ret_lines->insert(right.begin(), right.end());
			// here's returning (seekStr, setOfLines, fileContent)
			return QueryResult(rep(), ret_lines, left.get_file());
		}
};
Query operator |(const Query &lhs, const Query &rhs)
{
	// here will call private constructor of Query !!!
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

int main(int argc, char **argv)
{
	Query q = Query("fiery") & Query("bird") | Query("wind");
	ifstream is("/tmp/tmp");
	TextQuery text(is);
	QueryResult result = q.eval(text);
	result.show(cout);
	/* output:
	 *	((fiery & bird) | wind)
	 *	1: Her Daddy says when the wind blows
	 *	3: like a fiery bird in flight.
	 */

	return 0;
}

/* E.G. Text:
 * Alice Emma has long flowing red hair.
 * Her Daddy says when the wind blows
 * through her hair, it looks almost alive,
 * like a fiery bird in flight.
 * A beautiful fiery bird, he tells her,
 * magical but untamed.
 * "Daddy, shush, there is no such thing,"
 * she tells him, at the same time wanting
 * him to tell her more.
 * Shyly, she asks, "I mean, Daddy, is there?"
 */
