/* 2017.04.11 09:08
 * P_693
 * !!!
 * nonthrowing specification: 'noexcept' !!!
 * 1.	add in every declaration and definition expressions;
 * 2.	place before 'final', 'override', '=0' of virtual function,
 *	after '&', '&&', 'const';
 * 3.	throw exception in a 'noexcept' can be compiled and executed,
 *	program will call 'terminate' to promise the declaration of 'noexcept',
 *	so 'noexcept' can be using with two situations:
 *	a. nonexception
 *	b. don't [know how to] deal with any exception
 * 4.	noexcept(true)	// throw
 *	noexcept(false)	// nonthrow
 * 5.	'nonexcept' function pointer can only point to 'nonexcept' function
 * 6.	'noexcept' in inheriting
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base {
	public:
		static void Show();
		/* if 'Show()' throwing, 'ShowAll()' throwing, else nonthrowing
		 * 'noexcept(Show())' like 'sizeof()' won't value expression
		 */
		void ShowAll() noexcept(noexcept(Show()));
		virtual double F1() noexcept;
		virtual int F2() noexcept(false);
		virtual void F3() noexcept(false);
};
class Derived: public Base {
	public:
		//double F1();		// invalid, lost 'noexcept'
		int F2();		// valid
		void F3() noexcept;	// valid
};


int main(int argc, char **argv)
{

	return 0;
}

