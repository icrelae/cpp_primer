/* 2016.10.16 15:57
 * P_220
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void manip(int, int);
double dobj;

int main(int argc, char **argv)
{
	// a: level-3, char to int
	manip('a', 'z');
	// b: level-4, double to int
	manip(55.4, dobj);

	return 0;
}

