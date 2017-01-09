/* 2016.12.13 22:10
 * P_345
 * !!!
 * custom operator instead of '<' !!!
 * sort(itBeg, itEnd, funcCompare)
 * stable_sort(itBeg, itEnd, funcCompare): stable sort
 * partition(itBeg, itEnd, funcCustomCompare): split container into two segments,
 *	front half are funcCustomCompare() returned true,
 *	return iterator after first segment(see 10.13)
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsShorter(string const &s1, string const &s2)
{
	return s1.size() < s2.size();
}
void ElimDuplicates(vector<string> &vecStr)
{
	sort(vecStr.begin(), vecStr.end());
	auto end_unique = unique(vecStr.begin(), vecStr.end());
	vecStr.erase(end_unique, vecStr.end());
}
int main(int argc, char **argv)
{
	vector<string> vecStr({"as", "asd", "a", "b", "b", "bs"});
	ElimDuplicates(vecStr);
	//sort(vecStr.begin(), vecStr.end(), IsShorter);
	stable_sort(vecStr.begin(), vecStr.end(), IsShorter);
	for (auto const Str : vecStr)
		cout << Str << ' ';
	// output: a b as bs asd 

	return 0;
}

