/* 2016.08.29 22:42
 * P_101
 */
#include <iostream>
#include <vector>

using std::vector;

int main(int argc, char **argv)
{
	int tmp;
	vector<int> vec;
	void SumHeadTail(const vector<int> vec);
	void SumNeighboring(const vector<int> vec);
	
	while (std::cin >> tmp)
		vec.push_back(tmp);
	SumNeighboring(vec);
	SumHeadTail(vec);

	return 0;
}

void SumNeighboring(const vector<int> vec)
{
	vector<int>::const_iterator it = vec.begin();
	while (++ it != vec.end())
		std::cout << *it + *(it-1) << ' ';
	std::cout << std::endl;
}

void SumHeadTail(const vector<int> vec)
{
	vector<int>::const_iterator itBeg = vec.begin();
	vector<int>::const_iterator itEnd = vec.end() - 1;
	while (itBeg <= itEnd) {
		std::cout << *itBeg + *itEnd << ' ';
		++ itBeg;
		-- itEnd;
	}
	std::cout << std::endl;
}
