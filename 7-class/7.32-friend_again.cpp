/* 2016.10.29 22:05
 * P_253
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Screen;
class Window_mgr {
	public:
		void clear(vector<Screen>::size_type index);
	private:
		vector<Screen> screens = {};
		// vector<Screen> screens = {Screen()};
		/* this is error: invalid use of incomplete type 'class Screen',
		 * because definition of Screen() is behind of this!!!
		 */
};
class Screen {
	public:
		friend void Window_mgr::clear(vector<Screen>::size_type index);
	private:
		string content;
};
void Window_mgr::clear(vector<Screen>::size_type index)
{
	screens[index].content = "";
}

int main(int argc, char **argv)
{

	return 0;
}

