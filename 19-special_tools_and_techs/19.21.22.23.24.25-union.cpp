/* 2017.04.22 17:21
 * P_754
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

union Foo {
	char cval;
	int ival;
	double dval;
};
// anonymous union
// namespace-scoped anonymous union must be 'static'
static union {
	char anoCval;
	int anoIval;
	double anoDval;
};
void UnionEg()
{
	union {
		char anoCval;
		int anoIval;
		double anoDval;
	};
	anoCval = 'a';
	anoIval = 2;
}

class Token {
	public:
		Token(): tok(INT), ival(0) {
		}
		Token(const Token &t): tok(t.tok) {
			copyUnion(t);
		}
		Token(const Token &&t): tok(std::move(t.tok)) {
			copyUnion(std::move(t));
		}
		Token &operator=(const Token &t) {
			if (tok == STR && t.tok != STR)
				sval.~string();
			if (tok == STR && t.tok == STR)
				sval = t.sval;
			else
				copyUnion(t);
			tok = t.tok;
			return *this;
		}
		Token &operator=(const Token &&t) {
			if (tok == STR && t.tok != STR)
				sval.~string();
			if (tok == STR && t.tok == STR)
				sval = std::move(t.sval);
			else
				copyUnion(std::move(t));
			tok = std::move(t.tok);
			return *this;
		}
		~Token() {
			if (tok == STR)
				sval.~string();
		}
		Token &operator=(const string &s) {
			if (tok == STR)
				sval = s;
			else
				new(&sval) string(s);
			tok = STR;
			return *this;
		}
		Token &operator=(char c) {
			if (tok == STR)
				sval.~string();
			cval = c;
			tok = CHAR;
			return *this;
		}
		Token &operator=(int i) {
			if (tok == STR)
				sval.~string();
			ival = i;
			tok = INT;
			return *this;
		}
		Token &operator=(double d) {
			if (tok == STR)
				sval.~string();
			dval = d;
			tok = DBL;
			return *this;
		}
		void Show() {
			switch (tok) {
				case INT:
					cout << ival;
					break;
				case CHAR:
					cout << cval;
					break;
				case DBL:
					cout << dval;
					break;
				case STR:
					cout << sval;
					break;
			}
		}
	private:
		enum {
			INT,
			CHAR,
			DBL,
			STR,
		} tok;
		union {
			char cval;
			int ival;
			double dval;
			string sval;
		};
		void copyUnion(const Token &t) {
			switch (t.tok) {
				case Token::INT:
					ival = t.ival;
					break;
				case Token::CHAR:
					cval = t.cval;
					break;
				case Token::DBL:
					dval = t.dval;
					break;
				case Token::STR:
					sval = t.sval;
					break;
			}
		}
		void copyUnion(const Token &&t) {
			switch (t.tok) {
				case Token::INT:
					ival = std::move(t.ival);
					break;
				case Token::CHAR:
					cval = std::move(t.cval);
					break;
				case Token::DBL:
					dval = std::move(t.dval);
					break;
				case Token::STR:
					sval = std::move(t.sval);
					break;
			}
		}
};

int main(int argc, char **argv)
{
	Token t1;
	t1 = 'c';
	t1 = t1;
	t1.Show();
	t1 = "string";
	t1 = t1;
	t1.Show();

	return 0;
}

