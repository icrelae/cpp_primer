/* 2017.04.07 21:09
 * P_666
 */
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>

using namespace std;

void DistributionEG()
{
	default_random_engine e;
	/* all 'distribution' type are template, single argument templateType
	 * is type of number it generate;
	 * except only one dstribution: 'bernoulli_distribution'
	 * it's a class, return 'true' or 'false', default probability is 0.5
	 * empty '<>' using default type, here is 'double'
	 */
	uniform_real_distribution<> u(0, 1);

	// average 4, standard deviation 1.5
	normal_distribution<> n(4, 1.5);
	vector<unsigned> Vals(9);
	for (size_t i = 0; i != 100; ++i) {
		// to nearest integer
		unsigned v = lround(n(e));
		if (v < Vals.size())
			++Vals[v];
	}
	for (size_t j = 0; j != Vals.size(); ++j)
		cout << j << ": " << string(Vals[j], '*') << endl;
	/* output:
	 *	0: **
	 *	1: ***
	 *	2: *********
	 *	3: *****************
	 *	4: *********************************
	 *	5: ********************
	 *	6: *************
	 *	7: ***
	 *	8: 
	 */

	// here is 0.6 probability for 'true'
	bernoulli_distribution b(0.6);
	bool first = b(e);
}

int main(int argc, char **argv)
{
	DistributionEG();

	return 0;
}

