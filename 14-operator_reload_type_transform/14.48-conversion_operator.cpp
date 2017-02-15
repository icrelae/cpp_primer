/* 2017.01.18 09:01
 * P_517
 * no
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
		friend bool operator==(const Date&, const Date&);
		friend bool operator!=(const Date&, const Date&);
		friend bool operator<(const Date&, const Date&);
		Date& operator=(const Date&);
		Date& operator=(const Date&&) noexcept;
	private:
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
bool operator==(const Date &lhs, const Date &rhs)
{
	bool result = false;
	if (lhs.second == rhs.second &&
			lhs.minute == rhs.minute &&
			lhs.hour == rhs.hour &&
			lhs.day == rhs.day &&
			lhs.month == rhs.month &&
			lhs.year == rhs.year)
		result = true;
	return result;
}
bool operator!=(const Date &lhs, const Date &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const Date &lhs, const Date &rhs)
{
	bool result = true;
	if (lhs.year >= rhs.year ||
			lhs.month >= rhs.month ||
			lhs.day >= rhs.day ||
			lhs.hour >= rhs.hour ||
			lhs.minute >= rhs.minute ||
			lhs.second >= rhs.second)
		result = false;
	return result;
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
Date& Date::operator=(const Date &date)
{
	year = date.year;
	month = date.month;
	day = date.day;
	hour = date.hour;
	minute = date.minute;
	second = date.second;
	return *this;
}
Date& Date::operator=(const Date &&date) noexcept
{
	if (this != &date) {
		year = date.year;
		month = date.month;
		day = date.day;
		hour = date.hour;
		minute = date.minute;
		second = date.second;
	}
	return *this;
}

int main(int argc, char **argv)
{
	Date date;

	return 0;
}
