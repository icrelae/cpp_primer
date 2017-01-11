/* 2017.01.11 09:09
 * P_470
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

class StrVec {
	public:
		StrVec();
		StrVec(initializer_list<string>);
		StrVec(const StrVec&);
		StrVec& operator=(const StrVec&);
		~StrVec();
		void push_back(const string&);
		string* begin() const { return elements;}
		string* end() const { return first_free;}
		size_t size() const { return first_free - elements;}
		size_t capacity() const { return cap - elements;}
	private:
		void chk_n_alloc();
		pair<string*, string*> alloc_n_copy(const string*, const string*);
		void free();
		void reallocate();
		allocator<string> alloc;
		string *elements;
		string *first_free;
		string *cap;
};
StrVec::StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr)
{
}
StrVec::StrVec(initializer_list<string> lstStr)
{
	string *data = alloc.allocate(lstStr.size());
	elements = data;
	for (const auto &str : lstStr)
		alloc.construct(data++, str);
	cap = first_free = data;
}
StrVec::StrVec(const StrVec &orig)
{
	pair<string*, string*> newData = alloc_n_copy(orig.elements, orig.first_free);
	elements = newData.first;
	cap = first_free = newData.second;
}
StrVec& StrVec::operator=(const StrVec &rhs)
{
	pair<string*, string*> newData = alloc_n_copy(rhs.elements, rhs.first_free);
	free();
	elements = newData.first;
	cap = first_free = newData.second;
	return *this;
}
StrVec::~StrVec()
{
	free();
}
void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
void StrVec::free()
{
	//while (first_free != elements)
	//	alloc.destroy(--first_free);
	for_each(elements, first_free,
			[this] (string &s) {
				this->alloc.destroy(&s);
			});
	alloc.deallocate(elements, cap - elements);
	cap = first_free = elements = nullptr;
}
void StrVec::chk_n_alloc()
{
	if (size() == capacity())
		reallocate();
}
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	string *data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}
void StrVec::reallocate()
{
	size_t newCapacity = size() == 0 ? 1 : size() * 2;
	string *newData = alloc.allocate(newCapacity);
	string *elem = elements, *dest = newData;
	while (elem != first_free) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newData;
	first_free = dest;
	cap = elements + newCapacity;
}

using line_no = vector<std::string>::size_type;
class QueryResult;
class TextQuery {
	public:
		TextQuery(ifstream&);
		QueryResult query(const string&) const;
	private:
		shared_ptr<StrVec> file;
		map<string, shared_ptr<set<line_no>>> wm;
};
TextQuery::TextQuery(ifstream &is): file(new StrVec)
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
				shared_ptr<StrVec> f):
			sought(s), lines(p), file(f) { }
	private:
		string sought;
		shared_ptr<set<line_no>> lines;
		shared_ptr<StrVec> file;
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
	os << qr.sought << " occurs ";
	os << qr.lines->size() << ' ' << "times" << endl;
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
 *	a occurs 3 times
 *		(line 1) a c
 *		(line 2) a b
 *		(line 3) a b c,
 *	b occurs 2 times
 *		(line 2) a b
 *		(line 3) a b c,
 *	c occurs 1 times
 *		(line 1) a c
 */
