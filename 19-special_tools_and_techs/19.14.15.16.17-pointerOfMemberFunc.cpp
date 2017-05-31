/* 2017.04.22 12:20
 * P_744
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Screen {
	public:
		using Action = Screen& (Screen::*)();
		enum Directions {
			HOME,
			FAORWARD,
			BACK,
			UP,
			DOWN,
		};
		Screen& move(Directions d) {
			/*this->*Menu[d]();
			 * invalid, equal to 'this->*(Menu[d]())',
			 * using pointer of member returned by 'Menu[d]()'
			 */
			(this->*Menu[d])();
		}
	public:
		static Action Menu[];
		Screen& home();
		Screen& forward();
		Screen& back();
		Screen& up();
		Screen& down();
};
Screen::Action Screen::Menu[] = {
	&Screen::home,
	&Screen::forward,
	&Screen::back,
	&Screen::up,
	&Screen::down,
};
void PointerOfMemberFunc()
{
	Screen sc;
	sc.move(Screen::HOME);
	sc.move(Screen::DOWN);
}

// Ex_19.16
class Sales_data {
	public:
		double avg_price;
};
using AVGPRICE = double Sales_data::*;
AVGPRICE avgp = &Sales_data::avg_price;

// Ex_19.17
using SC_MOVE = Screen& (Screen::*)(Screen::Directions);
SC_MOVE scMove = &Screen::move;
using SC_HOME = Screen& (Screen::*)();
SC_HOME scHome = &Screen::home;
SC_HOME scForward = &Screen::forward;
SC_HOME scUp = &Screen::up;
SC_HOME scDown = &Screen::down;


int main(int argc, char **argv)
{

	return 0;
}

