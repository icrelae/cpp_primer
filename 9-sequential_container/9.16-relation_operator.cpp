/* 2016.11.19 16:12
 * P_305
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

bool Compare(vector<int> a, list<int> b)
{
	vector<int> tmp(b.begin(), b.end());
	return a == tmp;
}

int main(int argc, char **argv)
{

	return 0;
}

