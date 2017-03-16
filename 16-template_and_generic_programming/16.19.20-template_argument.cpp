/* 2017.03.16 09:10
 * P_595
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T, typename VT = vector<T>>
void ShowVector(const vector<T> &vec)
{
	typename VT::size_type i = 0;
	while (i < vec.size())
		cout << vec[i++] << ' ';
}

template<typename T, typename VT = vector<T>>
void ShowVector2(const vector<T> &vec)
{
	typename VT::const_iterator it = vec.begin();
	while (it != vec.end())
		cout << *it++ << ' ';
}

int main(int argc, char **argv)
{
	vector<int> vecInt{0, 1, 2, 3, 4, 5};
	ShowVector(vecInt);
	ShowVector2(vecInt);

	return 0;
}

