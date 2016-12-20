/* 2016.12.14 22:35
 * P_349
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Sum(int const &intNum)
{
	int x = 30;
	auto lmdSum = [x] (int const &intNum) {
		return (x + intNum);
	};
	return lmdSum(intNum);
}
int main(int argc, char **argv)
{
	cout << Sum(20) << endl;

	return 0;
}

