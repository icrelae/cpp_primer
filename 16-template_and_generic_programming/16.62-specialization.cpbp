/* 2017.03.27 20:15
 * P_629
 * !!!
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
class Sales_data
{
	friend std::hash<Sales_data>;
	public:
		Sales_data(string bookNo = "", 
				unsigned int units_sold = 0, 
				double revenue = 0);
		Sales_data& combine(const Sales_data &rhs);
		string isbn() const;
		string bookNo;
		unsigned int units_sold = 0;
		double revenue = 0.0;
		friend istream& operator>>(istream&, Sales_data&);
		friend ostream& operator<<(ostream&, const Sales_data&);
		friend Sales_data operator+(const Sales_data&, const Sales_data&);
		friend bool operator==(const Sales_data&, const Sales_data&);
		Sales_data& operator+=(const Sales_data&);
		Sales_data& operator=(const Sales_data&);
		Sales_data& operator=(const string&);
};
Sales_data::Sales_data(string bookNo, unsigned int units_sold, double revenue)
{
	this->bookNo = bookNo;
	this->units_sold = units_sold;
	this->revenue = revenue;
}
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
string Sales_data::isbn() const
{
	return bookNo;
}
istream& operator>>(istream &is, Sales_data &data)
{
	double price;
	is >> data.bookNo >> data.units_sold >> price;
	data.revenue = data.units_sold * price;
	return is;
}
ostream& operator<<(ostream &os, const Sales_data &data)
{
	os << data.bookNo << ' ';
	os << data.units_sold << ' ';
	os << data.revenue;
	return os;
}
Sales_data operator+(Sales_data &dataA, Sales_data &dataB)
{
	Sales_data tmp;
	if (dataA.bookNo == dataB.bookNo) {
		tmp.bookNo = dataA.bookNo;
		tmp.units_sold = dataA.units_sold + dataB.units_sold;
		tmp.revenue = dataA.revenue + dataB.revenue;
	}
	return tmp;
}
Sales_data operator+=(Sales_data &dataA, Sales_data &dataB)
{
	if (dataA.bookNo == dataB.bookNo) {
		dataA.units_sold = dataA.units_sold + dataB.units_sold;
		dataA.revenue = dataA.revenue + dataB.revenue;
	}
	return dataA;
}
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data result;
	if (lhs.bookNo == rhs.bookNo) {
		result.bookNo = lhs.bookNo;
		result.units_sold = lhs.units_sold + rhs.units_sold;
		result.revenue = lhs.revenue + rhs.revenue;
	}
	return result;
}
Sales_data& Sales_data::operator+=(const Sales_data &data)
{
	//if (bookNo == data.bookNo) {
	//	units_sold += data.units_sold;
	//	revenue += data.revenue;
	//}
	Sales_data tmp = *this + data;
	if (bookNo == data.bookNo) {
		units_sold = tmp.units_sold;
		revenue = tmp.revenue;
	}

	return *this;
}
Sales_data& Sales_data::operator=(const Sales_data &data)
{
	bookNo = data.bookNo;
	units_sold = data.units_sold;
	revenue = data.revenue;
	return *this;
}
Sales_data& Sales_data::operator=(const string &isbn)
{
	bookNo = isbn;
	units_sold = 0;
	revenue = 0;
	return *this;
}
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.bookNo == rhs.bookNo;
}
namespace std {
	// template specialization for 'hash<>'!!!
	template<>
	struct hash<Sales_data> {
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data&) const;
	};
	size_t hash<Sales_data>::operator()(const Sales_data &s) const {
		return hash<string>()(s.bookNo) ^
			hash<unsigned>()(s.units_sold) ^
			hash<double>()(s.revenue);
	}
}


int main(int argc, char **argv)
{
	std::unordered_multiset<Sales_data> mset;
	Sales_data sd("Bible",10,0.98);

	// here need define 'operator==()' for 'Sales_data' !!!
	mset.emplace(sd);
	mset.emplace("C++ Primer",5, 9.99);

	for(const auto &item : mset)
		std::cout << "the hash code of " << item.isbn()
			<<":\n0x" << std::hex << std::hash<Sales_data>()(item)
			<< "\n";

	return 0;
}

