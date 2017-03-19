/* 2017.03.19 13:05
 * P_604
 *
 * 37. no
 * 38. using to determine the number of memory to allocate
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T1, typename T2, typename T3>
T1 sum(T2, T3);
template<typename T>
int compare(T, T);

void ExplicitArguEG()
{
	sum<long>(1.1, 2.2);

	long l;
	//compare(l, 10);		// invalid
	compare<long>(l, 10);		// valid
	compare<char>('a', 'b');	// valid
}


int main(int argc, char **argv)
{

	return 0;
}

