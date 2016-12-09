/* 2016.11.15 21:19
 * P_302
 */
#include <iostream>
#include <vector>
#include <list>

using namespace std;

void ShowVector(const vector<double> &vec)
{
	for (const auto i : vec) {
		cout << i << ' ';
	}
	cout << endl;
}
int main(int argc, char **argv)
{
	list<int> list{0, 1, 2, 3, 4};
	vector<int> veci{0, 1, 2, 3, 4};
	vector<double> vecd0(veci.begin(), veci.end());
	vector<double> vecd1(list.begin(), list.end());
	ShowVector(vecd0);
	ShowVector(vecd1);

	return 0;
}

