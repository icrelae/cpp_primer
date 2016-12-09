/* 2016.11.19 16:12
 * P_309
 */
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

using namespace std;

int main(int argc, char **argv)
{
	list<string> deqStr;
	string word;
	while (cin >> word)
		deqStr.push_front(word);
	for (const auto itDeqStr : deqStr)
		cout << itDeqStr << ' ';


	return 0;
}

