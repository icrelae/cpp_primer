/* 2017.01.15 15:23
 * P_493
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
		friend istream& operator>>(istream&, Date&);
		friend ostream& operator<<(ostream&, const Date&);
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
istream& operator>>(istream &is, Date &date)
{
	is >> date.year >> date.month >> date.day;
	is >> date.hour >> date.minute >> date.second;
	return is;
}
ostream& operator<<(ostream &os, const Date &date)
{
	os << date.year << date.month << date.day;
	os << date.hour << date.minute << date.second;
	return os;
}

int main(int argc, char **argv)
{
	Date date;

	return 0;
}
