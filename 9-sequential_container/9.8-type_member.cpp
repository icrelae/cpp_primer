/* 2016.11.15 21:06
 * !!!
 * difference_type, value_type, reference, const_reference !!!
 * 
 * list<string>::const_reference
 * list<string>::reference
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> vec(10);
	vector<int>::difference_type distance = vec.end() - vec.begin();
	vector<int>::value_type i = 10;		// int i = 10;
	vector<int>::reference reference = vec[0];
	vector<int>::const_reference cReference = vec[0];
	reference = -1;
	cout << vec[0];

	return 0;
}

