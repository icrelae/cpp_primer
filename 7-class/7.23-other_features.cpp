/* 2016.10.29 10:42
 * P_246
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Screen {
	private:
		/* using or typdef also have access specifiers!!! */
		typedef string::size_type Pos;
	public:
		Screen() = default;
		Screen(Pos ht, Pos wt, char c);
		char Get() const;
		char Get(Pos ht, Pos wd) const;
		size_t AccessCtr() const;
	private:
		Pos cursor;
		Pos height;
		Pos width;
		string contents;
		mutable size_t access_ctr = 0;
};
/* order of member initialization list should 
 * be same with declaration in class!!!
 * default value of parameters only appear one place:
 * either declaration or definition!!!
 */
Screen::Screen(Pos ht, Pos wd, char c):
	height(ht), width(wd), contents(ht * wd, c)
{
}
char Screen::Get() const
{
	return contents[cursor];
}
char Screen::Get(Pos ht, Pos wd) const
{
	return contents[ht * wd];
}
size_t Screen::AccessCtr() const
{
	/* mutable variable can be modified by const function!!! */
	return ++access_ctr;
}

int main(int argc, char **argv)
{

	return 0;
}

