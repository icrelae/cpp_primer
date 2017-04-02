/* 2017.04.01 08:42
 * P_650
 * !!!
 * regular expression: !!!
 *	header: <regex>
 *	runtime parsing regex, wrong expression throw exception 'regex_error e'
 *	regex(re, f);		// re: regular-expresion,
 *				// string| charId beg, end| char[]| char*, size_t| {'a', 'b', 'c'};
 *				// f: [regex|regex_constants]::syntax_option_type
 *	r1 = reg;
 *	r1.assign(re, f);
 *	r.mark_count();		// number of subexpression
 *	r.flags();		// return 'syntax_option_type'
 *	regex_match(seq, m, r, mft)	// seq: string| charIt beg, end| char[];
 *	regex_search(seq, m, r, mtf);	// m: match;
 *	regex_match(seq, r, mft);	// r: regex;
 *	regex_search(seq, r, mtf);	// mft: regex_constants::match_flag_type
 *	regex_replace
 *	sregex_iterator
 *	smatch			// container which keep result in it
 *	ssub_match		// result of matched subexpression in string
 *
 *	syntax_optiont_type:
 *		icase		// ignore case
 *		nosubs		// never store matched subexpression
 *		optimize	// execute speed take precedence over construct speed
 *		ECMAScript	// ECMA-262 grammer
 *		basic		// POSIX basic grammer
 *		extended	// POSIX extended grammer
 *		awk		// POSIX awk grammer
 *		grep		// POSIX grep grammer
 *		egrep		// POSIX egrep grammer
 */
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

void RegexEG() {
	smatch results;
	//string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");	// a
	string pattern("[^c]ei");				// b
	regex r1(pattern);
	string test_str = "receipt freind theif receive";
	if (regex_search(test_str, results, r1))
		cout << results.str() << endl;
	// output(a): freind
	// output(b): rei

	regex r2("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);

	try {
		regex r3("[[:alnum:]", regex::icase);
	} catch (regex_error e) {
		cout << e.what() << "\ncode: " << e.code() << endl;
	}
	/* output:
	 *	Unexpected character in bracket expression.
	 *	code: 4
	 */
}

int main(int argc, char **argv)
{
	RegexEG();

	return 0;
}

