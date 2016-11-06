/* 2016.10.30 16:28
 * P_263
 * invalid, NoDefault have no default constructor
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NoDefault {
	public:
		NoDefault(int i) {};
};

int main(int argc, char **argv)
{
	vector<NoDefault> vec(10);

	return 0;
}

