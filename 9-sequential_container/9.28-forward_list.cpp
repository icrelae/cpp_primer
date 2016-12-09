/* 2016.11.20 16:13
 * P_314
 */
#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

void InsertB(forward_list<string> &flst, 
		const string strA, const string strB)
{
	auto curr = flst.cbegin();
	auto prior = flst.cbefore_begin();
	while (curr != flst.cend() && *curr != strA) {
		++curr;
		++prior;
	}
	if (curr != flst.cend())
		flst.insert_after(curr, strB);
	else
		flst.insert_after(prior, strB);
}
int main(int argc, char **argv)
{
	forward_list<string> flst{"0", "1", "2", "3"};
	InsertB(flst, "1", "4");
	InsertB(flst, "3", "5");
	InsertB(flst, "6", "7");
	for (auto x : flst)
		cout << x << ' ';

	return 0;
}
