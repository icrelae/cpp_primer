/* 2016.10.29 10:42
 * P_246
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Screen {
	private:
		typedef string::size_type Pos;
	public:
		Screen() = default;
		Screen(Pos ht, Pos wd);
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
Screen::Screen(Pos ht, Pos wd):
	height(ht), width(wd), contents(ht * wd, ' ')
{
}
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
	return ++access_ctr;
}

int main(int argc, char **argv)
{

	return 0;
}

