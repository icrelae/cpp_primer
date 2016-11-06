/* 2016.10.05 17:11
 * P_193
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

int main(int argc, char **argv)
{
	// a: invalid
	calc(23.4, 55.1);
	// b: valid
	count("abcdefg", 'a');
	// c: valid
	calc(66);
	// d: valid
	sum(vec.begin(),vec.end(), 3.8);

	return 0;
}

