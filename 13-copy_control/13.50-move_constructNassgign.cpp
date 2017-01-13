/* 2017.01.12 20:13
 * P_481
 * !!!
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
		StrVec(StrVec&&) noexcept;
		StrVec& operator=(const StrVec&);
		StrVec& operator=(StrVec&&) noexcept;
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
	// move iterator: *mit=rvalue !!!
	string *last = uninitialized_copy(make_move_iterator(begin()),
				make_move_iterator(end()), newData);
	free();
	elements = newData;
	first_free = last;
	cap = elements + newCapacity;
}
// move-construct: parameter is 'StrVec &&' !!!
// 'noexcept' need to be specified both in-class and out-class !!!
StrVec::StrVec(StrVec &&s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
	// here will destruct s !!!
}
StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

/* HasPtr and moveEG */
class HasPtr {
	public:
		HasPtr(): ps(new string), i(1) { }
		HasPtr(HasPtr &p): ps(new string(*p.ps)), i(p.i) {
			cout << "in copy-constructor" << endl;
		}
		~HasPtr() {
			delete ps;
		}
		HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {
			cout << "in move-constructor" << endl;
			p.ps = nullptr;
		}
		// here '=' can be copy-assignment as well as move-assignment !!!
		void swap(HasPtr &hp) {
			using std::swap;
			swap(ps, hp.ps);
			swap(i, hp.i);
		}
		HasPtr& operator=(HasPtr rhs) {
			cout << "in assignment" << endl;
			using std::swap;
			this->swap(rhs);
			return *this;
		}
	private:
		string *ps;
		unsigned i;
};
void MoveEG()
{
	HasPtr hp, hp2, hp3;
	hp = hp2;		// copy-assignment
	hp = std::move(hp3);	// move-assignment
	/* output:
	 *	in copy-constructor
	 *	in assignment
	 *	in move-constructor
	 *	in assignment
	 */
}

/* String */
class String {
	public:
		String();
		String(const char*);
		String(const String&);
		String(String&&) noexcept;
		~String();
		String& operator=(const String&);
		String& operator=(String&&) noexcept;
		char* begin() const { return elements;}
		char* end() const { return first_free;}
		size_t size() const { return first_free - elements;}
	private:
		allocator<char> alloc;
		pair<char*, char*> alloc_n_copy(const char*, const char*);
		void free();
		char *elements;
		char *first_free;
		char *cap;
};
String::String(): elements(alloc.allocate(1))
{
	*elements = '\0';
	cap = first_free = elements + 1;
}
String::String(const String &s)
{
	pair<char*, char*> newData = alloc_n_copy(s.elements, s.first_free);
	elements = newData.first;
	cap = first_free = newData.second;
}
String::String(const char *cstrBeg)
{
	const char *cstrEnd = cstrBeg;
	while (*cstrEnd++ != '\0');
	first_free = elements = alloc.allocate(cstrEnd - cstrBeg);
	while (cstrBeg != cstrEnd)
		alloc.construct(first_free++, *cstrBeg++);
	cap = first_free;
}
String::~String()
{
	free();
}
String& String::operator=(const String &s)
{
	pair<char*, char*> newData = alloc_n_copy(s.elements, s.first_free);
	free();
	elements = newData.first;
	cap = first_free = newData.second;
	return *this;
}
pair<char*, char*> String::alloc_n_copy(const char *beg, const char *end)
{
	char *data = alloc.allocate(end - beg);
	return {data, uninitialized_copy(beg, end, data)};
}
void String::free()
{
	if (elements != nullptr && first_free != nullptr) {
		while (first_free != elements)
			alloc.destroy(--first_free);
		alloc.deallocate(elements, cap - elements);
		cap = first_free = elements = nullptr;
	}
}
String::String(String &&s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	cout << "in String move-constructor" << endl;
	s.elements = s.first_free = s.cap = nullptr;
}
String& String::operator=(String &&s) noexcept
{
	cout << "in String move-assignment" << endl;
	if (this != &s) {
		free();
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		s.cap = s.first_free = s.elements = nullptr;
	}
	return *this;
}

/* Message and Folder */
class Message;
class Folder {
	public:
		void addMsg(Message*);
		void remMsg(Message*);
	private:
		set<Message*> mesgs;
};
void Folder::addMsg(Message *m)
{
	mesgs.insert(m);
}
void Folder::remMsg(Message *m)
{
	mesgs.erase(m);
}

class Message {
	public:
		Message(const string &s = string());
		Message(const Message&);
		Message(Message&&);
		Message& operator=(const Message&);
		Message& operator=(Message&&);
		~Message();
		void swap(Message&);
		void save(Folder&);
		void remove(Folder&);
	private:
		string content;
		set<Folder*> folders;
		void add_to_folders(const Message&);
		void remove_from_folders();
		void move_folders(Message*);
};
void Message::save(Folder &folder)
{
	folder.addMsg(this);
	folders.insert(&folder);
}
void Message::remove(Folder &folder)
{
	folder.remMsg(this);
	folders.erase(&folder);
}
void Message::add_to_folders(const Message &m)
{
	for (auto &folder : m.folders)
		folder->addMsg(this);
}
void Message::remove_from_folders()
{
	for (auto &folder : folders)
		folder->remMsg(this);
}
void Message::swap(Message &m)
{
	using std::swap;
	swap(content, m.content);
	swap(folders, m.folders);
	for (auto &folder : folders) {
		folder->remMsg(this);
		folder->addMsg(&m);
	}
	for (auto &folder : m.folders) {
		folder->remMsg(&m);
		folder->addMsg(this);
	}
}
void swap(Message &ma, Message &mb)
{
	ma.swap(mb);
}
Message::Message(const string &s): content(s)
{
}
Message::Message(const Message &m): content(m.content), folders(m.folders)
{
	add_to_folders(m);
}
Message& Message::operator=(const Message &m)
{
	using std::swap;
	remove_from_folders();
	content = m.content;
	folders = m.folders;
	add_to_folders(m);

	return *this;
}
Message::~Message()
{
	remove_from_folders();
}
void Message::move_folders(Message *m)
{
	folders = std::move(m->folders);
	for (auto folder : folders) {
		folder->remMsg(m);
		folder->addMsg(this);
	}
	m->folders.clear();	// empty set
}
Message::Message(Message &&m): content(std::move(m.content))
{
	move_folders(&m);
}
Message& Message::operator=(Message &&m)
{
	if (this != &m) {
		remove_from_folders();
		content = std::move(m.content);
		move_folders(&m);
	}
	return *this;
}

int main(int argc, char **argv)
{
	vector<String> vecStr;
	for (int i = 0; i < 50; ++i)
		vecStr.push_back("asd");
	/* output:
	 *	in String move-constructor * 113
	 */

	return 0;
}
