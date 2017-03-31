/* 2017.03.31 09:08
 * P_645
 */
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

struct Foo10 {
	int ans;
	int update(const size_t id, const bool answer) {
		if (true == answer)
			ans |= 1 << id;
		else
			ans &= ~(1 << id);
		return ans;
	}
};
struct Foo100 {
	bitset<10> ans;
	bitset<10> update(const size_t id, const bool answer) {
		ans[id] = answer;
		return ans;
	}
};

void BitsetEg()
{
	Foo10 f10 = { .ans = 0};
	Foo100 f100 = { .ans = 0};
	for (size_t i = 0; i < 10; ++i)
		if (i % 2 == 0)
			f10.ans |= 1 << i;
		else
			f10.ans &= ~(1 << i);
	for (size_t i = 0; i < f100.ans.size(); ++i)
		if (i % 2 == 0)
			f100.ans.set(i);
		else
			f100.ans.reset(i);
	for (size_t i = 0; i < 10; ++i)
		cout << static_cast<bool>(f10.ans & (1 << i)) << ' ';
	cout << endl;
	cout << f100.ans;
	cout << endl;
	/* output:
	 *	1 0 1 0 1 0 1 0 1 0 
	 *	0101010101
	 */
	const int answers = 0x211;
	size_t score[2] = {0, 0};
	for (size_t i = 0; i < 10; ++i) {
		bool answer = answers & (1 << i);
		if (answer == static_cast<bool>(f10.ans & (1 << i)))
			++score[0];
		if (answer == f100.ans[i])
			++score[1];
	}
	cout << score[0] << ' ' << score[1];
	// output: 6 6
}
int main(int argc, char **argv)
{
	BitsetEg();

	return 0;
}

