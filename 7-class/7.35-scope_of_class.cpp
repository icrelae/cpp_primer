/* 2016.10.30 12:59
 * P_257
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef string Type;
Type initVal();
class Exercise {
	public:
		typedef double Type;
		/* double double */
		Type setVal(Type);
		/* double */
		Type initVal();
	private:
		int val;
};
/* string string */
//Type Exercise::setVal(Type parm)
/* double double */
Exercise::Type Exercise::setVal(Exercise::Type parm)
{
	val = parm + initVal();
	return val;
}

int main(int argc, char **argv)
{

	return 0;
}

