/* 2017.02.13 19:54
 * P_509
 */
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class StringLen {
	public:
		StringLen(): counter({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}), size(10)
		{
		}
		bool operator()(const string str) {
			bool ret = false;
			string::size_type strLength = str.size();
			if (strLength == size)
				ret = true;
			if (strLength <= size)
				++counter[strLength];
			else
				++counter[0];
			return ret;
		}
		void ShowCounter()
		{
			for (unsigned x : counter)
				cout << x << ' ';
		}
	private:
		array<unsigned, 11> counter;
		unsigned size;
};

int main(int argc, char **argv)
{
	string arrStr[] = {
		"1",
		"12",
		"123",
		"12345678901",
		"123456789012",
		"1234567890123",
	};
	StringLen sl;
	for (const string str : arrStr)
		sl(str);
	sl.ShowCounter();
	// output: 3 1 1 1 0 0 0 0 0 0 0 

	return 0;
}

