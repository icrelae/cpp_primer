/* 2017.04.06 21:19
 * P_659
 * !!!
 * 'regex_replace' and 'match_flag_type': !!!
 * m.format(dest, fmt, match_flag_type mft=format_default)
 *	// output 'm' according to 'fmt' to 'dest'
 * m.format(fmt, match_flag_type mft=format_default)
 *	// return string include output of 'm' according to 'fmt'
 * regex_replace(dest, seq, r, fmt, match_flag_type mft)
 * regex_replace(seq, r, fmt, match_flag_type mft)
 *	// output matched part of 'seq' using 'r' according to 'fmt'
 * std::regex_constants::match_flag_type:
 *	match_default		// equal to 'format_default'
 *	match_not_bol		// not treat first letter as begin-of-line
 *	match_not_eol		// not treat last letter as end-of-line
 *	match_not_bow		// no treat first letter as begin-of-word
 *	match_not_eow		// no treat last letter as end-of-word
 *	match_any		// return random match when there's more then one match
 *	match_not_null		// not match any empty sequence
 *	match_continuous	// match have to begin from first letter of input
 *	match_prev_avail	// input sequence include content before first match
 *	format_default		// replace string witch ECMAScript rules
 *	format_sed		// replace string witch POSIX sed rules
 *	format_no_copy		// don't output mismatched part
 *	format_first_only	// replace subexpression only first time
 */
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

using std::regex_constants::format_no_copy;
using namespace std::regex_constants;

void Regex_replaceEG()
{
	string fmt = "$2.$5.$7";
	string phonePattern = 
		"(\\()?(\\d{3})(\\))?([-. ])*(\\d{3})([-. ]*)(\\d{4})";
	regex r(phonePattern);
	string number = "(908) 555-1800";
	cout << regex_replace(number, r, fmt) << endl;
	// output: 908.555.1800
}

vector<string> vecStr {
	"morgan (201) 555-2368 862-555-0123",
		"drew (973)555.0130",
		"lee (609) 555-0132 20155550175 800.555-0000",
};
void Ex24()
{
	string fmt = "$2.$5.$7";
	string phonePattern = 
		"(\\()?(\\d{3})(\\))?([-. ])*(\\d{3})([-. ]*)(\\d{4})";
	regex r(phonePattern);
	for (const auto &str : vecStr) {
		cout << regex_replace(str, r, fmt) << endl;
	}
	/* output:
	 *	morgan 201.555.2368 862.555.0123
	 *	drew 973.555.0130
	 *	lee 609.555.0132 201.555.50175 800.555.0000
	 */
}
void Ex25()
{
	string fmt = "$2.$5.$7";
	string phonePattern = 
		"(\\()?(\\d{3})(\\))?([-. ])*(\\d{3})([-. ]*)(\\d{4})";
	regex r(phonePattern);
	smatch m;
	for (const auto &str : vecStr) {
		regex_search(str, m, r);
		cout << m.format(fmt) << endl;
		cout << regex_replace(str, r, fmt, format_no_copy|format_first_only) << endl;
	}
	/* output:
	 *	201.555.2368
	 *	201.555.2368
	 *	973.555.0130
	 *	973.555.0130
	 *	609.555.0132
	 *	609.555.0132
	 */
}
void Ex26()
{
	string fmt = "$2.$5.$7";
	string phonePattern = 
		"(\\()?(\\d{3})(\\))?([-. ])*(\\d{3})([-. ]*)(\\d{4})";
	regex r(phonePattern);
	smatch m;
	for (const auto &str : vecStr) {
		sregex_iterator it(str.begin(), str.end(), r), itEnd;
		m = *it;
		if (++it == itEnd)
			cout << m.format(fmt) << endl;
		else
			for ( ; it != itEnd; ++it)
				cout << it->format(fmt) << endl;
	}
	/* output:
	 *	862.555.0123
	 *	973.555.0130
	 *	201.555.5017
	 *	800.555.0000
	 */
}

int main(int argc, char **argv)
{
	vector<string> zipCode {
		"123456789",
		"12345-6789",
		"12345",
		"12345-678",
	};
	string ae = "(\\d{5})[-]?(\\d{4})";
	regex reg(ae);
	string fmt = "$1+$2";
	for (const auto &str : zipCode) {
		cout << regex_replace(str, reg, fmt) << endl;
	}
	/* output:
	 *	12345+6789
	 *	12345+6789
	 *	12345
	 *	12345-678
	 */

	return 0;
}

