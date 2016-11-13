/* 2016.11.07 22:01
 * P_283
 * !!!
 * endl; flush; ends; unitbuf; nounitbuf; tie !!!
 * exceptions will cause buffer stuck !!!
 * cout is relavant with cin, so cin will make cout refresh !!!
 * stream can tie with only one ostream pointer !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	// output a '\n' then refresh buffer
	cout << "asdf" << endl << '#';
	// output nothing then refresh buffer
	cout << "asdf" << flush << '#';
	// output a ' ' then refresh buffer
	cout << "asdf" << ends << '#';

	// cout after this all follow a flush
	cout << unitbuf;
	// with no flush
	cout << nounitbuf;

	// *a = cout
	ostream *a = cin.tie();
	cin.tie(NULL);
	cin.tie(&cout);

	return 0;
}

