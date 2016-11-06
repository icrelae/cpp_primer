/* 2016.10.30 14:37
 * P_261
 */
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class Date {
	public:
		Date();
		Date(struct tm const &p);
		Date(istream &is);
		int year;
		int month;
		int day;
		int hour;
		int minute;
		int second;
};
Date::Date()
{
	const time_t t = time(NULL);
	struct tm const *p = localtime(&t);
	year = p->tm_year;
	month = p->tm_mon;
	day = p->tm_mday;
	hour = p->tm_hour;
	minute = p->tm_min;
	second = p->tm_sec;
}
Date::Date(struct tm const &p):
	year(p.tm_year), month(p.tm_mon), day(p.tm_mday),
	hour(p.tm_hour), minute(p.tm_min), second(p.tm_sec)
{
}
Date::Date(istream &is)
{
	is >> year >> month >> day;
	is >> hour >> minute >> second;
}

int main(int argc, char **argv)
{
	Date date;

	return 0;
}
