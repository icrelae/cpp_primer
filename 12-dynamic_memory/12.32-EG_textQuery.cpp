/* 2017.01.05 22:25
 * P_435
 * set is unduplicated
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

using line_no = vector<std::string>::size_type;

class StrBlob {
	public:
		StrBlob();
		StrBlob(initializer_list<string> il);
		typedef vector<string>::size_type size_type;
		bool empty() const {return data->empty();}
		size_type size() const {return data->size();}
		void push_back(string const &str) { data->push_back(str);}
		void push_back(string const &str) const { data->push_back(str);}
		void pop_back();
		void pop_back() const;
		vector<string>::const_iterator begin();
		string& front();
		string& back();
		string const & front() const;
		string const & back() const;
	private:
		shared_ptr<vector<string>> data;
		void Check(size_type i, string const &msg) const;
};
StrBlob::StrBlob(): data(make_shared<vector<string>>())
{
}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il))
{
}
void StrBlob::Check(size_type i, string const &msg) const
{
	if (i >= this->size())
		throw out_of_range(msg);
}
vector<string>::const_iterator StrBlob::begin()
{
	return data->cbegin();
}
string& StrBlob::front()
{
	Check(0, "front on empty StrBlob");
	return data->front();
}
string& StrBlob::back()
{
	Check(0, "back on empty StrBlob");
	return data->back();
}
void StrBlob::pop_back()
{
	Check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
void StrBlob::pop_back() const
{
	Check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
string const & StrBlob::front() const
{
	Check(0, "const front on empty StrBlob");
	return const_cast<string const &>(data->front());
}
string const & StrBlob::back() const
{
	Check(0, "const back on empty StrBlob");
	return const_cast<string const &>(data->back());
}
class QueryResult;
class TextQuery {
	public:
		TextQuery(ifstream&);
		QueryResult query(const string&) const;
	private:
		shared_ptr<StrBlob> file;
		map<string, shared_ptr<set<line_no>>> wm;
};
TextQuery::TextQuery(ifstream &is): file(new StrBlob)
{
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}
class QueryResult {
	friend ostream & print(ostream &, QueryResult const &);
	public:
		QueryResult(string s, shared_ptr<set<line_no>> p,
				shared_ptr<StrBlob> f):
			sought(s), lines(p), file(f) { }
	private:
		string sought;
		shared_ptr<set<line_no>> lines;
		shared_ptr<StrBlob> file;
};
QueryResult TextQuery::query(string const &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
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

int main(int argc, char **argv)
{
	ifstream ifs("/tmp/input");
	TextQuery text(ifs);
	QueryResult resulta = text.query("a");
	QueryResult resultb = text.query("b");
	QueryResult resultc = text.query("c");
	print(cout, resulta);
	print(cout, resultb);
	print(cout, resultc);

	return 0;
}
/* /tmp/input:
 *	a c
 *	a b
 *	a b c,
 * output:
 *	aoccurs 3 3times
 *		(line 1) a c
 *		(line 2) a b
 *		(line 3) a b c,
 *	boccurs 2 2times
 *		(line 2) a b
 *		(line 3) a b c,
 *	coccurs 1 1times
 *		(line 1) a c
 */
