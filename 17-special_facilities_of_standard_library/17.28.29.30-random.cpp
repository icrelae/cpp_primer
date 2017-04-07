/* 2017.04.07 08:53
 * P_663
 * !!!
 * engine for random: !!!
 * header: <random>
 * Engine e;
 * Engine e(s);
 * e.seed(s)		// reset seed using s
 * e.min()		// return min value
 * e.max()		// return max value
 * Engine::result_type
 * e.discard(usigned long long n);	// push forward n step
 */
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

void RandomEG()
{
	// static egine generate vary value for each calling of 'RandomEG()'!!!
	static default_random_engine e;
	for (size_t i = 0; i < 4; ++i)
		cout << e() << ' ';
	cout << endl;
	// output: 16807 282475249 1622650073 984943658 
	
	// value of 'u' range between 0 and 9
	uniform_int_distribution<unsigned> u(0, 9);
	for (size_t i = 0; i < 4; ++i)
		// here passing 'e' to 'u' instead of 'e()' !!!
		// because some distribution calling engine more than once
		cout << u(e) << ' ';
	cout << endl;
	// output: 5 2 0 6 
}
unsigned Ex(unsigned min, unsigned max, unsigned seed = time(0))
{
	static default_random_engine e(seed);
	uniform_int_distribution<unsigned> distInt(min, max);
	return distInt(e);
}

int main(int argc, char **argv)
{
	for (size_t i = 0; i < 5; ++i)
		cout << Ex(-5, 5) << ' ';
	cout << endl;
	for (size_t i = 0; i < 5; ++i)
		cout << Ex(-5, 5, 0) << ' ';
	cout << endl;
	/* output:
	 *	2472763047 2687472473 3794886810 2495033427 540325247 
	 *	3559489993 1224111000 1609323287 4068725171 1023341142 
	 */

	return 0;
}

