/* 2016.10.16 11:29
 * P_206
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8, };
int (&arrPtr(int i))[5]
{
	return (i % 2) ? odd : even;
}
int main(int argc, char **argv)
{

	return 0;
}
