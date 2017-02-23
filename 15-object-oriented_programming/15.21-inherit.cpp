/* 2017.02.22 19:56
 * P_547
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Shape {
	public:
		virtual double Area() const = 0;
};
class Rectangle: public Shape {
	public:
		double Area() const override { return length * width;}
		Rectangle(const double l, const double w)
			: length(l), width(w) { }
	private:
		double length, width;
};
class Square: public Rectangle {
	public:
		double Area() const override { return Rectangle::Area();}
		Square(const double l): Rectangle(l, l) { }
};

int main(int argc, char **argv)
{

	return 0;
}

