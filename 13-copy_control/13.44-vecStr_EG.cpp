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

class String {
	public:
		String();
		String(const char*);
		String(const String&);
		~String();
		char* begin() const { return elements;}
		char* end() const { return first_free;}
		size_t size() const { return first_free - elements;}
	private:
		allocator<char> alloc;
		void alloc_n_copy(const char*, const char*);
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
	alloc_n_copy(s.elements, s.first_free);
}
String::String(const char *cstrBeg)
{
	const char *cstrEnd = cstrBeg;
	while (cstrEnd++ != '\0')
		cstrEnd;
	first_free = elements = alloc.allocate(cstrEnd - cstrBeg);
	while (cstrBeg != cstrEnd)
		alloc.construct(first_free++, *cstrBeg++);
	cap = first_free;
}
String::~String()
{
	free();
}
void String::alloc_n_copy(const char *beg, const char *end)
{
	char *data = alloc.allocate(end - beg);
	free();
	first_free = elements = data;
	while (beg != end)
		alloc.construct(first_free, *beg++);
	cap = first_free;
}
void String::free()
{
	while (first_free != elements)
		alloc.destroy(--first_free);
	alloc.deallocate(elements, cap - elements);
	cap = first_free = elements = nullptr;
}

int main(int argc, char **argv)
{

	return 0;
}
