/* 2017.03.04 22:11
 * P_574
 * !!!
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
		string erasePunc(string str) {
			static set<char> punctuations{' ', ',', '.', ';'};
			for (auto itStr = str.begin(); itStr != str.end(); ++itStr) {
				if (punctuations.find(*itStr) != punctuations.end()) {
					itStr = str.erase(itStr) - 1;
				}
			}
			return str;
		}
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
			word = erasePunc(word);
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
		virtual Query_base* clone() const & = 0;
		virtual Query_base* clone() && = 0;
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
		virtual QueryResult eval(const TextQuery &t) const override {
			// here's returning (seekStr, setOfLines, fileContent)
			return t.query(query_word);
		}
		virtual string rep() const override {
			return query_word;
		}
		// add copy-constructor and copy-assignment for clone() !!!
		WordQuery(const WordQuery&) = default;
		WordQuery(const WordQuery &&wq):
			query_word(std::move(wq.query_word)) {
			}
		WordQuery& operator=(const WordQuery&) = default;
		WordQuery& operator=(const WordQuery && wq) {
			query_word = std::move(wq.query_word);
			return *this;
		}
		virtual WordQuery* clone() const & override {
			return new WordQuery(query_word);
		}
		virtual WordQuery* clone() && override {
			return new WordQuery(std::move(query_word));
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
		~Query() {
			delete q;
			q = NULL;
		}
		virtual QueryResult eval(const TextQuery &t) const {
			// here's 'q' can be AndQuery, OrQuery or WordQuery !!!
			return q->eval(t);
		}
		virtual string rep() const {
			return q->rep();
		}
		// add copy-constructor and copy-assignment for clone() !!!
		Query(const Query &query): q(query.clone()) {
		}
		Query(const Query &&wq):
			q(std::move(wq).clone()) {
			}
		Query& operator=(const Query &query) {
			delete q;
			q = query.clone();
			return *this;
		}
		Query& operator=(const Query && query) {
			delete q;
			q = std::move(query).clone();
			return *this;
		}
		virtual Query_base* clone() const & {
			return q->clone();
		}
		virtual Query_base* clone() && {
			return std::move(q)->clone();
		}
	private:
		// all friend operator(~|&) will call this constructor !!!
		Query(Query_base *query): q(query) {
		}
		Query_base *q;
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

		virtual QueryResult eval(const TextQuery &text) const override {
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
		virtual string rep() const override {
			return "~(" + query.rep() + ")";
		}
		// add copy-constructor and copy-assignment for clone() !!!
		NotQuery(const NotQuery &nq): query(nq.query) {
		}
		NotQuery(const NotQuery &&nq):
			query(std::move(nq.query)) {
			}
		NotQuery& operator=(const NotQuery &nq) {
			query = nq.query;
			return *this;
		}
		NotQuery& operator=(const NotQuery && nq) {
			query = std::move(nq.query);
			return *this;
		}
		virtual NotQuery* clone() const & override {
			return new NotQuery(*this);
		}
		virtual NotQuery* clone() && override {
			return new NotQuery(std::move(*this));
		}
		Query query;
};
Query operator ~(const Query &operand)
{
	// here will call private constructor of Query !!!
	return (new NotQuery(operand));
}

class BinaryQuery: public Query_base {
	protected:
		BinaryQuery(const Query &l, const Query &r, string s):
			lhs(l), rhs(r), opSym(s) {
			}
		virtual QueryResult eval(const TextQuery&) const override = 0;
		virtual string rep() const override {
			return "(" + lhs.rep() + " "
				+ opSym + " "
				+ rhs.rep() + ")";
		}
		// add copy-constructor and copy-assignment for clone() !!!
		BinaryQuery(const BinaryQuery &bq):
			lhs(bq.lhs), rhs(bq.rhs), opSym(bq.opSym) {
			}
		BinaryQuery(const BinaryQuery &&bq):
			lhs(std::move(bq.lhs)), rhs(std::move(bq.rhs)),
			opSym(std::move(bq.opSym))  {
			}
		BinaryQuery& operator=(const BinaryQuery &bq) {
			lhs = bq.lhs;
			rhs = bq.rhs;
			opSym = bq.opSym;
			return *this;
		}
		BinaryQuery& operator=(const BinaryQuery && bq) {
			lhs = std::move(bq.lhs);
			rhs = std::move(bq.rhs);
			opSym = std::move(bq.opSym);
			return *this;
		}
		virtual BinaryQuery* clone() const & = 0;
		virtual BinaryQuery* clone() && = 0;
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
		// add copy-constructor and copy-assignment for clone() !!!
		AndQuery(const AndQuery &aq):BinaryQuery(aq) {
		}
		AndQuery(const AndQuery &&aq):BinaryQuery(std::move(aq)) {
		}
		AndQuery& operator=(const AndQuery &aq) {
			BinaryQuery::operator=(aq);
			return *this;
		}
		AndQuery& operator=(const AndQuery && aq) {
			BinaryQuery::operator=(std::move(aq));
			return *this;
		}
		virtual AndQuery* clone() const & {
			return new AndQuery(*this);
		}
		virtual AndQuery* clone() && {
			return new AndQuery(*std::move(this));
		}
};
Query operator &(const Query &lhs, const Query &rhs)
{
	// here will call private constructor of Query !!!
	return (new AndQuery(lhs, rhs));
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
		// add copy-constructor and copy-assignment for clone() !!!
		OrQuery(const OrQuery &oq):BinaryQuery(oq) {
		}
		OrQuery(const OrQuery &&oq):BinaryQuery(std::move(oq)) {
		}
		OrQuery& operator=(const OrQuery &oq) {
			BinaryQuery::operator=(oq);
			return *this;
		}
		OrQuery& operator=(const OrQuery && oq) {
			BinaryQuery::operator=(std::move(oq));
			return *this;
		}
		virtual OrQuery* clone() const & {
			return new OrQuery(*this);
		}
		virtual OrQuery* clone() && {
			return new OrQuery(*std::move(this));
		}
};
Query operator |(const Query &lhs, const Query &rhs)
{
	// here will call private constructor of Query !!!
	return (new OrQuery(lhs, rhs));
}
class History {
	public:
		vector<shared_ptr<Query>>::size_type add_query(const Query &q) {
			query_rec.push_back(make_shared<Query>(q));
		}
		void showAll(ostream &os) {
			for (auto q : query_rec) {
				os << *q << endl;
			}
		}
	private:
		vector<shared_ptr<Query>> query_rec;
};

int main(int argc, char **argv)
{
	History history;
	Query q = Query("fiery") & Query("bird") | Query("wind");
	ifstream is("/tmp/tmp");
	TextQuery text(is);
	QueryResult result = q.eval(text);
	history.add_query(q);
	history.showAll(cout);
	result.show(cout);
	/* output:
	 *	((fiery & bird) | wind)
	 *	((fiery & bird) | wind)
	 *	1: Her Daddy says when the wind blows
	 *	3: like a fiery bird in flight.
	 *	4: A beautiful fiery bird, he tells her,
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
