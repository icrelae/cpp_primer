/* 2017.01.18 20:05
 * P_592
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

template<typename T> class Vec;
template<typename T>
bool operator==(const Vec<T>&, const Vec<T>&);
template<typename T>
bool operator!=(const Vec<T>&, const Vec<T>&);
template<typename T>
bool operator<(const Vec<T>&, const Vec<T>&);
/* Vec */
template<typename T>
class Vec {
	public:
		Vec();
		Vec(initializer_list<T>);
		Vec(const Vec&);
		~Vec();
		Vec(Vec&&) noexcept;
		Vec& operator=(const Vec&);
		Vec& operator=(Vec&&) noexcept;
		friend bool operator==<T>(const Vec&, const Vec&);
		friend bool operator!=<T>(const Vec&, const Vec&);
		friend bool operator< <T>(const Vec&, const Vec&);
		Vec& operator=(initializer_list<T>);
		T& operator[](size_t);
		const T& operator[](size_t) const;
		void push_back(const T&);
		void push_back(T&&);
		T* begin() const { return elements;}
		T* end() const { return first_free;}
		size_t size() const { return first_free - elements;}
		size_t capacity() const { return cap - elements;}
	private:
		void chk_n_alloc();
		pair<T*, T*> alloc_n_copy(const T*, const T*);
		void free();
		void reallocate();
		allocator<T> alloc;
		string *elements;
		string *first_free;
		string *cap;
};
template<typename T>
Vec<T>::Vec(): elements(nullptr), first_free(nullptr), cap(nullptr)
{
}
template<typename T>
Vec<T>::Vec(initializer_list<T> lstStr)
{
	T *data = alloc.allocate(lstStr.size());
	elements = data;
	for (const auto &str : lstStr)
		alloc.construct(data++, str);
	cap = first_free = data;
}
template<typename T>
Vec<T>::Vec(const Vec<T> &orig)
{
	pair<T*, T*> newData = alloc_n_copy(orig.elements, orig.first_free);
	elements = newData.first;
	cap = first_free = newData.second;
}
template<typename T>
Vec<T>& Vec<T>::operator=(const Vec<T> &rhs)
{
	pair<T*, T*> newData = alloc_n_copy(rhs.elements, rhs.first_free);
	free();
	elements = newData.first;
	cap = first_free = newData.second;
	return *this;
}
template<typename T>
Vec<T>::~Vec()
{
	free();
}
template<typename T>
void Vec<T>::push_back(const T &s)
{
	cout << "in lvalue push_back" << endl;
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
// rvalue reload member function !!!
template<typename T>
void Vec<T>::push_back(T &&s)
{
	cout << "in rvalue push_back" << endl;
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}
template<typename T>
void Vec<T>::free()
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
template<typename T>
void Vec<T>::chk_n_alloc()
{
	if (size() == capacity())
		reallocate();
}
template<typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
	T *data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}
template<typename T>
void Vec<T>::reallocate()
{
	size_t newCapacity = size() == 0 ? 1 : size() * 2;
	T *newData = alloc.allocate(newCapacity);
	// move iterator: *mit=rvalue !!!
	T *last = uninitialized_copy(make_move_iterator(begin()),
				make_move_iterator(end()), newData);
	free();
	elements = newData;
	first_free = last;
	cap = elements + newCapacity;
}
// move-construct: parameter is 'Vec &&' !!!
// 'noexcept' need to be specified both in-class and out-class !!!
template<typename T>
Vec<T>::Vec(Vec &&s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
	// here will destruct s !!!
}
template<typename T>
Vec<T>& Vec<T>::operator=(Vec<T> &&rhs) noexcept
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
template<typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs)
{
	if (&lhs == &rhs)
		return true;
	bool result = true;
	size_t sizeLhs = lhs.size(), sizeRhs = rhs.size();
	if (sizeLhs == sizeRhs) {
		string *dataLhs = lhs.begin(), *dataRhs = rhs.begin();
		for (size_t i = 0; i < sizeLhs; ++i) {
			if (*(dataLhs + i) != *(dataRhs + i)) {
				result = false;
				break;
			}
		}
	} else {
		result = false;
	}
	return result;
}
template<typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs)
{
	return !(lhs == rhs);
}
template<typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs)
{
	bool result = true;
	T *dataLhs = lhs.begin(), *dataRhs = rhs.begin();
	while (dataLhs != lhs.end() && dataRhs != rhs.end()) {
		if (*dataLhs++ >= *dataRhs++) {
			result = false;
			break;
		}
	}
	if (result == true && lhs.size() >= rhs.size())
		result = false;
	return result;
}
template<typename T>
Vec<T>& Vec<T>::operator=(initializer_list<T> li)
{
	pair<T*, T*> newData = alloc_n_copy(li.begin(), li.end());
	free();
	elements = newData.first;
	cap = first_free = newData.second;
	return *this;
}
template<typename T>
T& Vec<T>::operator[](size_t n)
{
	return elements[n];
}
template<typename T>
const T& Vec<T>::operator[](size_t n) const
{
	return elements[n];
}
void RvalueReloadEG()
{
	Vec<string> vec;
	string str = "asd";
	vec.push_back(str);
	vec.push_back("qwe");
	/* output:
	 *	in lvalue push_back
	 *	in rvalue push_back
	 */
}

int main(int argc, char **argv)
{
	RvalueReloadEG();

	return 0;
}
