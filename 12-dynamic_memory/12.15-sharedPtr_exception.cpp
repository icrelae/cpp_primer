/* 2016.12.29 19:06
 * P_417
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

