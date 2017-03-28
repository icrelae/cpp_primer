/* 2017.03.28 08:54
 * P_629
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
size_t TimesOf(const vector<T> vec, T target)
{
	size_t times = 0;
	for (const auto obj : vec)
		times += obj == target ? 1 : 0;
	return times;
}
template<>
size_t TimesOf(const vector<const char*> vec, const char *target)
{
	size_t times = 0;
	for (const auto obj : vec) {
		times += string(obj) == string(target) ? 1 : 0;
	}
	return times;
}

int main(int argc, char **argv)
{
	vector<double> vecDob{0.1, 0.2, 0.3, 0.2, 0.2};
	vector<int> vecInt{1, 2, 3, 2, 2};
	vector<string> vecStr{"a", "b", "c", "b", "b"};
	char cstr[] = "asd", cstr2[] = "asd";
	const char *cp = cstr2;
	vector<const char*> vecCstr{cstr, cstr, cstr};
	cout << TimesOf(vecDob, 0.2) << ' ';
	cout << TimesOf(vecInt, 2) << ' ';
	cout << TimesOf(vecStr, string("b")) << ' ';
	cout << TimesOf(vecCstr, cp) << ' ';

	return 0;
}

