/* 2017.04.12 09:29
 * P_704
 */
#include <iostream>
#include <string>
#include <vector>

using std::string;	// 'usinng declaration'
using namespace std;	// 'using directive'

namespace mathLib {
	namespace MatrixLib {
		class matrix { };
	}
}
namespace alias = mathLib;

namespace Exercise {
	int iVar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int iVar = 0;
//using namespace Exercise;		// lead all of 'Exercise' in this file
void manip()
{
	using namespace Exercise;	// lead all of 'Exercise' in this func
	double dVar = 3.14;
	int iobj = limit + 1;
	//++iVar;			// ambiguous reference
	++::iVar;
}

int main(int argc, char **argv)
{

	return 0;
}

