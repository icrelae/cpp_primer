/* 2016.11.28 22:08
 * P_328
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DateType {
	public:
		DateType(const string &str);
		void ShowDate()
		{
			cout << year << ' ' << month << ' ' << day << endl;
		}
	private:
		unsigned year;
		unsigned month;
		unsigned day;
		static const string monthStrArray[12];
		void Constructor0(const string &str);	// January 1,1990
		void Constructor1(const string &str);	// 1/1/1990
		void Constructor2(const string &str);	// Jan 1 1990
};
const string DateType::monthStrArray[12] = {
	"January", "February", "March", "April", 
	"May", "June", "July", "August", 
	"September", "October", "November", "December"
};
DateType::DateType(const string &str)
{
	if (str.find(',') != string::npos)
		Constructor0(str);
	else if (str.find('/') != string::npos)
		Constructor1(str);
	else
		Constructor2(str);
}
void DateType::Constructor0(const string &str)
{
	/* January 1,1990*/
	string monthStr = str.substr(0, str.find(' '));
	for (size_t i = 0; i < 12; ++i)
		if (monthStrArray[i] == monthStr)
			this->month = i+1;
	day = stoi(str.substr(str.find(' ')));
	year = stoi(str.substr(str.find(',') + 1));
}
void DateType::Constructor1(const string &str)
{
	/* 1/1/1990 */
	day = stoi(str);
	month = stoi(str.substr(str.find('/') + 1));
	year = stoi(str.substr(str.find_last_of('/') + 1));
	
}
void DateType::Constructor2(const string &str)
{
	/* Jan 1 1990 */
	string monthStr = str.substr(0, str.find(' '));
	for (size_t i = 0; i < 12; ++i)
		if (monthStrArray[i].substr(0, 3) == monthStr)
			this->month = i+1;
	day = stoi(str.substr(str.find(' ')));
	year = stoi(str.substr(str.find_last_of(' ')));
}

int main(int argc, char **argv)
{
	string dateStrArr[] = {
		"January 1,1990", "1/1/1990", "Jan 1 1990", 
		"December 31,2009", "31/12/2009", "Dec 31 2009"
	};
	for (auto const &date : dateStrArr) {
		DateType dt(date);
		dt.ShowDate();
	}

	return 0;
}

