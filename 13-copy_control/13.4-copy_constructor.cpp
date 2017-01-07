/* 2017.01.07 20:53
 * P_443
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point {
	public:
		Point() {}
		Point(Point &p)
		{
			static int i = 0;
			cout << ++i << ' ';
		}
};
Point global;
Point foo(Point arg)	// 1 copy
{
	Point local = arg;	// 1 copy
	Point *heap = new Point(global);	// 1 copy
	*heap = local;
	Point pa[4] = {local, *heap};	// 2 copy
	return *heap;	// 1 copy
}

int main(int argc, char **argv)
{
	Point p(foo(global));
	// output: 1 2 3 4 5 6

	return 0;
}

