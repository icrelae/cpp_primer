/* 2017.03.15 21:13
 * P_592
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <unsigned H, unsigned W> class Screen;
template <unsigned H, unsigned W>
ostream& operator<<(ostream&, const Screen<H, W>&);
template <unsigned H, unsigned W>
istream& operator>>(istream&, Screen<H, W>&);

template <unsigned H, unsigned W>
class Screen {
	private:
		typedef string::size_type Pos;
		// here's second arg 'const Screen&' can be added '<H,W>' or not, both correct !!!
		friend ostream& operator<<<H, W>(ostream&, const Screen&);
		friend istream& operator>><H, W>(istream&, Screen<H, W>&);
	public:
		//Screen(): Screen(0, 0, ' ') {};
		Screen() = default;
		Screen(Pos ht, Pos wt, char c = ' ');
		char Get() const;
		char Get(Pos ht, Pos wd) const;
		Screen& Set(char c);
		Screen<H, W>& Set(Pos ht, Pos wd, char c);
		Screen<H, W>& Move(Pos ht, Pos wd);
		Screen<H, W>& Display(ostream &os);
		const Screen &Display(ostream &os) const;
		size_t AccessCtr() const;
		Pos Size() const;
	private:
		Pos cursor = 0;
		Pos height = H;
		Pos width = W;
		string contents;
		mutable size_t access_ctr = 0;
		void DoDisplay(ostream &os) const
		{
			os << contents;
		};
};
template <unsigned H, unsigned W>
Screen<H, W>::Screen(Pos ht, Pos wd, char c):
	height(ht), width(wd), contents(ht * wd, c)
{
}
template <unsigned H, unsigned W>
char Screen<H, W>::Get() const
{
	return contents[cursor];
}
template <unsigned H, unsigned W>
char Screen<H, W>::Get(Pos ht, Pos wd) const
{
	return contents[ht * wd];
}
template <unsigned H, unsigned W>
size_t Screen<H, W>::AccessCtr() const
{
	return ++access_ctr;
}
template <unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::Set(char c)
{
	contents[cursor] = c;
	return *this;
}
template <unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::Set(Pos ht, Pos wd, char c)
{
	contents[ht * wd] = c;
	return *this;
}
template <unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::Move(Pos ht, Pos wd)
{
	cursor = ht * width + wd;
	return *this;
}
template <unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::Display(ostream &os)
{
	DoDisplay(os);
	return *this;
}
template <unsigned H, unsigned W>
const Screen<H, W>& Screen<H, W>::Display(ostream &os) const
{
	DoDisplay(os);
	return *this;
}
template <unsigned H, unsigned W>
typename Screen<H, W>::Pos Screen<H, W>::Size() const
{
	return (height * width);
}

template <unsigned H, unsigned W>
ostream& operator<<(ostream &os, const Screen<H, W> &scr)
{
	for (size_t i = 0; i < scr.height; ++i) {
		os << scr.contents.substr(i*scr.width, scr.width) << endl;
	}
	return os;
}
template <unsigned H, unsigned W>
istream& operator>>(istream &is, Screen<H, W> &scr)
{
	is >> scr.contents;
	return is;
}

void ScreenEG()
{
	Screen<10, 5> scrEg(2, 2, 'x');
	scrEg.Display(cout);
	/* output: xxxxxxxxx */
}

int main(int argc, char **argv)
{
	Screen<2, 5> scr;
	cin >> scr;
	cout << scr;

	return 0;
}

