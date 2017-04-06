/* 2017.04.03 11:42
 * P_656
 * subexpression: ssub_match !!!
 * ssm.matched		// bool, whether a 'ssub_match' matched
 * ssm.first|second	// head it and past-the-end it, equal when mismatched
 * length()		// size of matched part, return 0 when 'matched()' is false
 * str()		// return matched part or empty string
 * str = ssub		// equal to 'str=ssub.str()', transform not explicit
 */
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

bool ValidPhoneNo(const smatch& m)
{
	// m[0]: whole matched
	// m[1]: first subexpression
	if (m[1].matched)
		return m[3].matched &&
			(m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched &&
			m[4].str() == m[6].str();
}

int main(int argc, char **argv)
{
	string phonePattern = 
		"(\\()?(\\d{3})(\\))?([-. ])*(\\d{3})([-. ]*)(\\d{4})";
	regex r(phonePattern);
	smatch m;
	string arrStr[] = {
		"(123)456-7890",
		"(123456-7890)",
	};
	//for (auto s = begin(arrStr); s != end(arrStr); ++s) {
	for (auto s : arrStr) {
		//sregex_iterator it(s->begin(), s->end(), r), end_it;
		sregex_iterator it(s.begin(), s.end(), r), end_it;
		if (ValidPhoneNo(*it))
			cout << "valid: " << it->str() << endl;
		else
			cout << "not valid: " << it->str() << endl;
	}

	string ae = "\\d{5}[-]?\\d{4}?";

	return 0;
}

