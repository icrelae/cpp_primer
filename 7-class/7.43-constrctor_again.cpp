/* 2016.10.30 16:28
 * P_263
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NoDefault {
	public:
		NoDefault(int i) {};
};

class C {
	public:
		C(): no(0) { }
	private:
		NoDefault no;
};

int main(int argc, char **argv)
{

	return 0;
}

