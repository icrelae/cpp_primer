/* 2017.03.15 08:22
 * P_592
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

template<typename> class BlobPtr;
template<typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T>
class Blob {
	private:
		// friend template function !!!
		friend class BlobPtr<T>;
	public:
		typedef T value_type;
		typedef typename vector<T>::size_type size_type;
		Blob();
		Blob(initializer_list<T> il);
		size_type size() const {
			return data->size();
		}
		bool empty() const {
			return data->empty();
		}
		void push_back(const T &t) {
			data->push_back(t);
		}
		void push_back(T &&t) {
			data->push_back(std::move(t));
		}
		void pop_back();
		T& back();
		/* dependent scope !!!
		 * here's 'typename' have to be placed befor 'vector<T>::size_type',
		 * because compiler can't deduce the 'vector<T>::size_type' is
		 * whether a type , func or other things with lazy instantiation
		 */
		T& operator[] (typename vector<T>::size_type);
	private:
		shared_ptr<vector<T>> data;
		void check(size_type, const string&) const;
};
template<typename T>
Blob<T>::Blob(): data(make_shared<Blob::value_type>())
{
}
template<typename T>
Blob<T>::Blob(initializer_list<T> il): data(make_shared<Blob::value_type>(il))
{
}
template<typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}
template<typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}
template<typename T>
T& Blob<T>::operator[](typename vector<T>::size_type i)
{
	check(i, "subscript out of range");
	return data->at(i);;
}
template<typename T>
void Blob<T>::check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template<typename T>
class BlobPtr {
	private:
		friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	public:
		BlobPtr():curr(0) {
		}
		BlobPtr(Blob<T> &a, typename vector<T>::size_type sz = 0):
			wptr(a.data), curr(sz) {
		}
		T& operator*() const {
			auto p = check(curr, "dereference past end");
			return (*p)[curr];
		}
		BlobPtr& operator++() {
			++curr;
			check(curr, "increment past end of BlobPtr");
		}
		BlobPtr& operator--() {
			--curr;
			check(curr, "decrement past end of BlobPtr");
		}
		BlobPtr& operator++(int) {
			BlobPtr<T> bp = *this;
			++(*this);
			return bp;
		}
		BlobPtr& operator--(int) {
			BlobPtr<T> bp = *this;
			--(*this);
			return bp;
		}
	private:
		shared_ptr<vector<T>>
			check(typename vector<T>::size_type, const string&) const;
		weak_ptr<vector<T>> wptr;
		typename vector<T>::size_type curr;
};
template<typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(typename vector<T>::size_type n,
		const string &msg) const
{
	shared_ptr<vector<T>> ptr = wptr.lock();
	if (ptr == nullptr)
		throw runtime_error("unbound weat_ptr");
	if (ptr->size() <= n)
		throw out_of_range(msg);
	return ptr;
}

template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return (lhs.wptr.lock() == rhs.wptr.lock());
}

int main(int argc, char **argv)
{
	BlobPtr<string> a, b;
	if (a == b);

	return 0;
}

