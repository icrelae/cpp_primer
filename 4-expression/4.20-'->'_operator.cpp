/* 2016.09.24 21:30
 * P_134
 */
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	std::vector<int>::iterator iter;

	*iter++;	// return *iter then ++iter
	(*iter)++;	// return *iter then *iter = *iter + 1
	*iter.empty();	// error: *(iter.empty())
	iter->empty();	// error: iter have no function empty()
	++*iter;	// *iter = *iter + 1
	iter++->empty();	// error: iter->empty() then ++iter

	return 0;
}

