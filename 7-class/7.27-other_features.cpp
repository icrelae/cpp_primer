/* 2016.10.29 11:49
 * P_249
 * !!!
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
		Screen &Set(char c);
		Screen &Set(Pos ht, Pos wd, char c);
		Screen &Move(Pos ht, Pos wd);
		Screen &Display(ostream &os);
		const Screen &Display(ostream &os) const;
		size_t AccessCtr() const;
	private:
		Pos cursor = 0;
		Pos height;
		Pos width;
		string contents;
		mutable size_t access_ctr = 0;
		void DoDisplay(ostream &os) const
		{
			/* writing in class, default inline!!! */
			os << contents;
		};
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
	/* return *this, so you can using it like obj.Display().set()!!! */
	return *this;
}
const Screen &Screen::Display(ostream &os) const
{
	DoDisplay(os);
	/* *this of constant function is a constant pointer!!! */
	return *this;
}

int main(int argc, char **argv)
{
	Screen myScreen(5, 3, 'X');
	const Screen blank(5, 3, '0');

	// non const Display
	myScreen.Display(cout);
	// const Display
	blank.Display(cout);

	myScreen.Move(4, 0).Set('#').Display(cout);
	cout << '\n';
	myScreen.Display(cout);

	return 0;
}

