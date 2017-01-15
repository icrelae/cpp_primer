/* 2017.01.15 15:36
 * P_495
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

class String {
	public:
		String();
		String(const char*);
		String(const String&);
		~String();
		String& operator=(const String&);
		friend ostream& operator<<(ostream&, const String&);
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
ostream& operator<<(ostream &os, const String &str)
{
	char *cp = str.elements;
	while (cp != str.first_free)
		os << *cp;
	return os;
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

int main(int argc, char **argv)
{

	return 0;
}
