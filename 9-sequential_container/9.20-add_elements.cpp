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
	list<int> list{0, 1, 2, 3, 4, 5, 6, 7, 8};
	deque<int> deqIntOdd, deqIntEvent;
	for (const auto itList : list) {
		if ((itList%2) == 1)
			deqIntOdd.push_front(itList);
		else
			deqIntEvent.push_front(itList);
	}
	for (const auto itDeq : deqIntOdd)
		cout << itDeq << ' ';
	cout << endl;
	for (const auto itDeq : deqIntEvent)
		cout << itDeq << ' ';

	return 0;
}

