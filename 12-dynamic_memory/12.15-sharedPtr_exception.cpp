/* 2016.12.29 19:06
 * P_417
 * !!!
 * regulation of smart pointer: !!!
 *	don't initialize several sptr using single common ptr
 *	never delete return value of sptr.get()
 *	never initialize or reset() a sptr using return value of sptr.get()
 *	remember that return value of sptr.get() will be invalid when last obj
 *		of it's corresponding sptr is destruct
 *	using deleter to manage some resource to avoid exception interrupt
 *		releaseing resource
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Destination { public: string dest;};
class Connection {
	public:
		Connection(Destination d): dest(d.dest) {}
		string dest;
};
Connection Connect(Destination *dp)
{
	return Connection(*dp);
}
void Disconnect(Connection &c)
{
	c.dest = "";
}
void ProcessCommonPtr(Destination &d)
{
	Connection c = Connect(&d);
	// if you forgot to call Disconnect(c), it won't close correctly
}

void end_connection(Connection *p)
{
	Disconnect(*p);
}
void ProcessSptr(Destination &d)
{
	Connection c = Connect(&d);
	shared_ptr<Connection> p(&c,
			[] (Connection *c) {
				Disconnect(*c);
			});
	// when ProcessSptr() end even though end by exception, Disconnect()
	// will always be called by 'shared_ptr<Connection> p'
}

int main(int argc, char **argv)
{

	return 0;
}

