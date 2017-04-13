/* 2017.04.12 09:29
 * P_701
 * !!!
 * define namespace: !!!
 * using unnamed namespace instead of 'static' to limit scope in single file
 * namespace can be discontinuous
 * namespace can be nested, inner names override outer names
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* unnamed namespace */
namespace {
	int staFooI;
}
namespace {
	string staFooStr;
}

namespace mathLib {
	namespace MatrixLib {
		class matrix { };
	}
}

mathLib::MatrixLib:: matrix mat;

int main(int argc, char **argv)
{

	return 0;
}

