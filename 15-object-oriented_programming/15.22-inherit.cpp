/* 2017.02.22 19:56
 * P_547
 * !!!
 * virtual-destructor: !!!
 *	virtual-destructor is using for destruct dynamic-type pointer or reference
 * 	correctly; it is not necessary if class have no other virtual function,
 * 	because virtual-function-table will expand the size of class
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Shape {
	public:
		virtual double Area() const = 0;
		virtual ~Shape() = default;
};
class Rectangle: public Shape {
	public:
		double Area() const override { return length * width;}
		Rectangle(const double l, const double w)
			: length(l), width(w) { }
		virtual ~Rectangle() { cout << "destruct rectangle;";}
	private:
		double length, width;
};
class Square: public Rectangle {
	public:
		double Area() const override { return Rectangle::Area();}
		Square(const double l): Rectangle(l, l) { }
		virtual ~Square() { cout << "destruct square;";}
};

int main(int argc, char **argv)
{
	Shape *p = new Square(3);
	cout << "area: " << p->Area() << endl;
	delete(p);
	/* output: 
	 *	area: 9
	 *	destruct square;
	 *	destruct rectangle;
	 */

	return 0;
}

