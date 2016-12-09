/* 2016.11.20 12:09
 * P_311
 * !!!
 * front(), back(): return reference of first/last element !!!
 * array don't have front(), forward_list don't have back() !!!
 * if seq-container is empty, fiont()/back() is undefined behaviour !!!
 * seqContainer[n], seqContainer.at(n) only available for string/vector/deque/array, not available for list/forward_list !!!
 * at() will throw exception of 'out_of_range' when index out of range !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void AccessElementsEG()
{
	vector<int> vec{0, 1, 2, 3, 4, 5};
	// avoid undefind behaviour caused by empty container !!!
	if (!vec.empty()) {
		// val = val2
		auto val = *vec.begin();
		auto val2 = vec.front();
		// val3 = val4
		auto last = vec.end();
		auto val3 = *(--last);
		auto val4 = vec.back();

		vec.front() = 32;	// vec[0] = 32
		auto &v0 = vec.back();
		v0 = 42;		// vec[0] = 42
		auto v1 = vec.back();
		v1 = 52;		// vec[0] = 42
	}
}

int main(int argc, char **argv)
{
	vector<int> c{1};
	if (!c.empty()) {
		auto val = *c.begin(), val2 = c.front();
		auto last = c.end();
		auto val3 = *(--last);
		auto val4 = c.back();
		// output: 1 1 1 1
		cout << val << ' ';
		cout << val2 << ' ';
		cout << val3 << ' ';
		cout << val4 << ' ';
	}

	return 0;
}

