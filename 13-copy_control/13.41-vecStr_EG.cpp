/* 2017.01.11 09:09
 * P_470
 *
 * |str	|raw	|construct	|
 * |	|	|first_free	|
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>

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
	while (first_free != elements)
		alloc.destroy(--first_free);
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

int main(int argc, char **argv)
{

	return 0;
}

