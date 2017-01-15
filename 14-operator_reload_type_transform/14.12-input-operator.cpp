/* 2017.01.15 16:49
 * P_496
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
		friend ostream& operator<<(ostream&, const Date&);
		friend istream& operator>>(istream&, Date&);
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
ostream& operator<<(ostream &os, const Date &date)
{
	os << date.year << ' ' << date.month << ' ' << date.day << ' ' ;
	os << date.hour << ' ' << date.minute << ' ' << date.second;
	return os;
}
istream& operator>>(istream &is, Date &date)
{
	int year, month, day, hour, minute, second;
	is >> year >> month >> day;
	is >> hour >> minute >> second;
	if (is) {
		date.year = year;
		date.month = month;
		date.day = day;
		date.hour = hour;
		date.minute = minute;
		date.second = second;
	}
	return is;
}

int main(int argc, char **argv)
{
	Date date;

	return 0;
}
