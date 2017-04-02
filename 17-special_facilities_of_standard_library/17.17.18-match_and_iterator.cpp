/* 2017.04.02 10:52
 * P_653
 * !!!
 * match and iterator of regex !!!
 * sregex_iterator it(b, e, re);	// it point to first match of 're' between 'b' to 'e'
 * sregex_iterator end;			// past-the-end iterator
 * *it, it->				// return 'smatch&' or 'smatch*'
 * ++it, it++
 * it1 == it2
 * it1 != it2
 *
 * m.ready()		// return 'true' if laready calling 'regex_search' or
 *			// 'regex_match' to set 'm', else return 'false';
 *			// any operate for 'm' which 'm.ready()' is 'false' are undefined:
 * m.size()		// if match failed, return 0, else return number of subexpression
 * m.empty()		// return 'true' if 'm.size()' is 0
 * m.prefix()		// an obj of 'ssub_match', sequence before current match
 * m.suffix()		// an obj of 'ssub_match', sequence after current match
 * m.format(...)
 * m.length(n)		// size of nth match
 * m.position(n)	// distance between nth match from sequence beginning
 * m.str(n)		// nth matched string
 * m[n]			// nth 'ssub_match' obj of subexpression
 * m.begin(), m.end()
 * m.cbegin(), m.cend()	// 'sub_match' range in 'm'
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <set>

using namespace std;

void RegexEG() {
	smatch results;
	string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");	// a
	regex r1(pattern);
	string test_str = "receipt freind theif receive";
	sregex_iterator end_it;
	for (sregex_iterator it(test_str.begin(), test_str.end(), r1);
			it != end_it; ++it) {
		cout << it->str() << ' ';
		// output: freind theif
	}
	cout << endl;

	for (sregex_iterator it(test_str.begin(), test_str.end(), r1);
			it != end_it; ++it) {
		auto pos = it->prefix().length();
		pos = pos > 40 ? pos - 40 : 0;
		cout << "prefix: " << it->prefix().str().substr(pos)
			<< "\n\t\t>>> " << it->str() << " <<<\n"
			<< "suffix: " << it->suffix().str().substr(0, 40)
			<< endl;
	}
	cout << endl;
	/* output:
	 *	prefix: receipt 
	 *			>>> freind <<<
	 *	suffix:  theif receive
	 *	prefix:  
	 *			>>> theif <<<
	 *	suffix:  receive
	 */

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
	smatch results;
	string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");	// a
	regex r1(pattern);
	string test_str = "albeit neighbor receipt freind theif receive";
	set<string> except{"albeit", "neighbor"};
	sregex_iterator end_it;
	for (sregex_iterator it(test_str.begin(), test_str.end(), r1);
			it != end_it; ++it) {
		if (except.find(it->str()) == except.end())
			cout << it->str() << ' ';
		// output: freind theif
	}

	return 0;
}

