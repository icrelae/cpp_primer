/* 2016.10.04 19:50
 * P_168
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int CheckPrefix(const vector<int> vec1, const vector<int> vec2)
{
	const vector<int> *pv1 = &vec1;
	const vector<int> *pv2 = &vec2;
	if (vec1.size() > vec2.size()) {
		pv1 = &vec2;
		pv2 = &vec1;
	}
	for (vector<int>::size_type i = 0; i < pv1->size(); ++ i)
		if ((*pv1)[i] != (*pv2)[i])
			return 0;
	return 1;
}
int main(int argc, char **argv)
{
	vector<int> vec1 = {0, 1, 1, 2};
	vector<int> vec2 = {0, 1, 1, 2, 3, 5, 8};
	vector<int> vec3 = {0, 1, 1};
	vector<int> vec4 = {0, 1, 2};

	cout << CheckPrefix(vec1, vec2) << endl;
	cout << CheckPrefix(vec1, vec3) << endl;
	cout << CheckPrefix(vec1, vec4) << endl;

	return 0;
}

