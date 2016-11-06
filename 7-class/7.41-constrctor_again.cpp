/* 2016.10.30 16:13
 * P_262
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Screen {
	private:
		typedef string::size_type Pos;
	public:
		Screen(): Screen(0, 0, ' ') {};
		Screen(Pos ht, Pos wd): Screen(ht, wd, ' ') {};
		Screen(Pos ht, Pos wt, char c);
		char Get() const;
		char Get(Pos ht, Pos wd) const;
		Screen &Set(char c);
		Screen &Set(Pos ht, Pos wd, char c);
		Screen &Move(Pos ht, Pos wd);
		Screen &Display(ostream &os);
		const Screen &Display(ostream &os) const;
		size_t AccessCtr() const;
		Pos Size() const;
	private:
		Pos cursor = 0;
		Pos height;
		Pos width;
		string contents;
		mutable size_t access_ctr = 0;
		void DoDisplay(ostream &os) const
		{
			os << contents;
		};
};
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
Screen &Screen::Set(char c)
{
	contents[cursor] = c;
	return *this;
}
Screen &Screen::Set(Pos ht, Pos wd, char c)
{
	contents[ht * wd] = c;
	return *this;
}
Screen &Screen::Move(Pos ht, Pos wd)
{
	cursor = ht * width + wd;
	return *this;
}
Screen &Screen::Display(ostream &os)
{
	DoDisplay(os);
	return *this;
}
const Screen &Screen::Display(ostream &os) const
{
	DoDisplay(os);
	return *this;
}
Screen::Pos Screen::Size() const
{
	return (height * width);
}

int main(int argc, char **argv)
{

	return 0;
}

