/* 2016.08.28 15:19
 * P_94
 * SumNeighboring calculate the sum of neighboring int
 * SumNeighboring calculate the sum of head's and tail's int
 */
#include <iostream>
#include <vector>

using std::vector;

int main(int argc, char **argv)
{
	int tmp;
	vector<int> vec;
	void SumNeighboring(const vector<int> &vec);
	void SumHeadTail(const vector<int> &vec);

	while (std::cin >> tmp)
		vec.push_back(tmp);
	for (auto &i : vec)
		std::cout << i << ' ';
	std::cout << std::endl;
	SumNeighboring(vec);
	SumHeadTail(vec);

	return 0;
}

void SumNeighboring(const vector<int> &vec)
{
	vector<int>::size_type index = 0;
	for (index = 0; index < vec.size()-1; ++ index)
		std::cout << vec[index] + vec[index+1] << ' ';
	std::cout << std::endl;
}
void SumHeadTail(const vector<int> &vec)
{
	vector<int>::size_type indexMin = 0;
	vector<int>::size_type indexMax = vec.size()-1;
	unsigned int time = indexMax / 2 + 1;
	
	for (unsigned int x = 0; x < time; ++ x)
		std::cout << vec[x] + vec[indexMax - x] << ' ';
	std::cout << std::endl;
}
/* input:
 * 1 2 3 4 5 
 * output:
 * 3 5 7 9 
 * 6 6 6 
 */
