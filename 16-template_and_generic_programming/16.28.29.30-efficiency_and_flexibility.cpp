/* 2017.03.18 09:29
 * P_600
 * efficiency and flexibility !!!
 * deleter of shared_ptr can be reseted which means it can be bind dynamically,
 * flexibal but inefficient
 * unique_ptr cannot be bind dynamically, efficient but inflexible
 */
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class DefaultDelete {
	public:
		DefaultDelete(ostream &s = cout): os(s) {
		}
		template<typename T>
		void operator()(T *ptr) {
			//os << "delete pointer" << endl;
			delete ptr;
		}
	private:
		ostream &os;
};

template<typename T>
class shared_pointer {
	public:
		shared_pointer(): refCount(new size_t(0)) {
		}
		shared_pointer(T *p, function<void(T*)> del=DefaultDelete()):
			ptr(p), deleter(del), refCount(new size_t(1)){
		}
		shared_pointer(const T& sp):
			ptr(sp.ptr), deleter(sp.deleter),
			refCount(new size_t(++sp.refCount)){
		}
		shared_pointer(const T&& sp) {
			decrement_n_destroy();
			using std::swap;
			swap(ptr, sp.ptr);
			swap(refCount, sp.refCount);
			swap(deleter, sp.deleter);

		}
		~shared_pointer() {
			decrement_n_destroy();
		}

		operator bool() const {
			return ptr == nullptr ? false : true;
		}
		T& operator =(const T& sp) {
			++(*sp.refCount);
			decrement_n_destroy();
			ptr = sp.ptr;
			refCount = sp.refCount;
			deleter = sp.deleter;
		}
		T& operator =(const T&& sp) noexcept {
			decrement_n_destroy();
			using std::swap;
			swap(ptr, sp.ptr);
			swap(refCount, sp.refCount);
			swap(deleter, sp.deleter);
		}
		T& operator *() const {
			return *ptr;
		}
		T* operator ->() const {
			return &(this->operator*());
		}

		size_t use_count() const {
			return *refCount;
		}
		T* get() {
			return ptr;
		}
		bool unique() const {
			/* shared_ptr<int> sp;
			 * cout << sp.unique();
			 * output: 0
			 */
			return *refCount == 1;
		}
		void reset() {
			decrement_n_destroy();
		}
		void reset(T *p) {
			if (ptr != p) {
				decrement_n_destroy();
				ptr = p;
				refCount = new size_t(1);
			}
		}
		void reset(T *p, function<void(T*)> del) {
			reset(p);
			deleter = del;
		}
	private:
		T *ptr;
		function<void(T*)> deleter;
		size_t *refCount;
		void decrement_n_destroy() {
			if (ptr != nullptr) {
				if (--(*refCount) == 0) {
					deleter(ptr);
					delete refCount;
				}
				ptr = nullptr;
				refCount = nullptr;
			}
		}
};

template<typename T, typename D = DefaultDelete>
class unique_pointer {
	public:
		unique_pointer(T &up): ptr(up) {
		}
		unique_pointer(const unique_pointer&) = delete;
		unique_pointer(const unique_pointer &&up): ptr(up.ptr) {
			up.ptr = nullptr;
		}
		~unique_pointer() {
			deleter(ptr);
			ptr = nullptr;
		}

		unique_pointer& operator =(const unique_pointer&) = delete;
		unique_pointer& operator =(const unique_pointer &&up) {
			if (ptr != up.ptr) {
				deleter(ptr);
				ptr = up.ptr;
				up.ptr = nullptr;
			}
			return *this;
		};
		T& operator *() const {
			return *ptr;
		}
		T* operator ->() const {
			return &(this->operator*());
		}
		operator bool() {
			return ptr == nullptr ? false : true;
		}

		T* get() {
			return ptr;
		}
		void reset() {
			deleter(ptr);
			ptr = nullptr;
		}
		void reset(T *up) {
			if (up != ptr) {
				deleter(ptr);
				ptr = up;
			}
		}
		T* release() {
			T *ret = ptr;
			ptr = nullptr;
			return ret;
		}
	private:
		T *ptr;
		D deleter;
};

template<typename T>
class Blob {
	public:
		typedef T value_type;
		typedef typename vector<T>::size_type size_type;
		Blob();
		Blob(typename vector<T>::const_iterator, typename vector<T>::const_iterator);
		Blob(initializer_list<T> il);
		size_type size() const {
			return data->size();
		}
		bool empty() const {
			return data->empty();
		}
		typename vector<T>::iterator begin() {
			return data->begin();
		}
		typename vector<T>::iterator end() {
			return data->end();
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
		shared_pointer<vector<T>> data;
		void check(size_type, const string&) const;
};
template<typename T>
Blob<T>::Blob(): data(new vector<T>)
{
}
template<typename T>
Blob<T>::Blob(typename vector<T>::const_iterator itBeg,
		typename vector<T>::const_iterator itEnd):
	data(new vector<T>(itBeg, itEnd))
{
}
template<typename T>
Blob<T>::Blob(initializer_list<T> il): data(new vector<Blob::value_type>(il))
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
int main(int argc, char **argv)
{
	Blob<string> strBlob = {"1", "11", "111"};
	Blob<string> arrSb[] = {
		{},
		{"2", "22", "222"},
		{strBlob.begin(), strBlob.end()}
	};
	for (auto sb : arrSb) {
		sb.push_back("4");
		sb.push_back("44");
		sb.pop_back();
		for (auto str : sb) {
			cout << str << ' ';
		}
		cout << endl;
	}

	return 0;
}

