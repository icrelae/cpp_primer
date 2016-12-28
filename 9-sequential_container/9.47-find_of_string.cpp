/* 2016.11.27 12:50
 * P_327
 * !!!
 * find of string: !!!
 * str.find(args)
 * str.rfind(args)
 * str.find_first_of(args): find place where any character of args first appear
 * str_find_last_of(args): find place where any character of args last appear
 * str.find_first_not_of(args): find place where not any character of args first appear
 * str.find_last_not_of(args): find place where not any character of args last appear
 * 
 * args:
 * ch, pos: find ch from pos which default is 0
 * str2, pos: find str2 from pos which default is 0
 * cp, pos: find content of char pointer from pos which default is 0
 * cp, pos, n: find first n characters of content of cp from pos,
 *	pos and n have no default value
 * return:
 * string::size_type or string::npos
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Split0(const string str)
{
	string::size_type i = 0;
	while ((i = str.find_first_of("0123456789", i)) != string::npos) {
		cout << str[i];
		++i;
	}
	i = 0;
	while ((i = str.find_first_of("abcdRE", i)) != string::npos) {
		cout << str[i];
		++i;
	}
}
void Split1(const string str)
{
	string::size_type i = 0;
	while ((i = str.find_first_not_of("abcdRE", i)) != string::npos) {
		cout << str[i];
		++i;
	}
	i = 0;
	while ((i = str.find_first_not_of("0123456789", i)) != string::npos) {
		cout << str[i];
		++i;
	}
}
int main(int argc, char **argv)
{
	string str = "ab2c3d7R4E6";
	Split0(str);
	Split1(str);

	return 0;
}

