/* 2016.12.05 23:02
 */
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string DropSpaceInStr(string str)
{
	while (str.find(' ') != string::npos)
		str.erase(str.find(' '));
	return str;
}
bool IsValidOperator(char const chaOprt)
{
	string const strValidOprts("+-*/()");
	if (strValidOprts.find(chaOprt) != string::npos)
		return true;
	else
		return false;
}
int GetIndexOfOprt(char const chaOprt)
{
	int index = -1;
	switch (chaOprt) {
		case '#': index = 0; break;
		case '+': index = 1; break;
		case '-': index = 2; break;
		case '*': index = 3; break;
		case '/': index = 4; break;
		case '(': index = 5; break;
		case ')': index = 6; break;
		default: /* TODO: error */ throw(0);
	}
	return index;
}
char GetPriority(char const chaOprtA, char const chaOprtB)
{
	/*
	 * |   | # | + | - | * | / | ( | ) |
	 * |---|---|---|---|---|---|---|---|
	 * | # | = | < | < | < | < | < |   |
	 * | + | > | > | > | < | < | < | > |
	 * | - | > | > | > | < | < | < | > |
	 * | * | > | > | > | > | > | < | > |
	 * | / | > | > | > | > | > | < | > |
	 * | ( |   | < | < | < | < | < | = |
	 * | ) |   |   |   |   |   |   |   |
	 */
	char const priorityTable[][7] = {
		{'=', '<', '<', '<', '<', '<', ' '},
		{'>', '>', '>', '<', '<', '<', '>'},
		{'>', '>', '>', '<', '<', '<', '>'},
		{'>', '>', '>', '>', '>', '<', '>'},
		{'>', '>', '>', '>', '>', '<', '>'},
		{' ', '<', '<', '<', '<', '<', '='}
	};
	int row = GetIndexOfOprt(chaOprtA);
	int col = GetIndexOfOprt(chaOprtB);
	return priorityTable[row][col];
}
double ValueOf(double const a, double const b, char const oprt)
{
	double result = 0;
	switch (oprt) {
		case '+': result = a + b; break;
		case '-': result = a - b; break;
		case '*': result = a * b; break;
		case '/': result = a / b; break;
		default: /* TODO: error */ throw(0);
	}
	return result;
}
/* value substring of str from sizPos and keep pos after value in str */
double SubStr2Double(string const str, string::size_type &sizPos)
{
	string::size_type sizTmp;
	double dblValue = stod(str.substr(sizPos), &sizTmp);
	sizPos += sizTmp;
	return dblValue;
}
double ValueMidExp(string strMidExp)
{
	stack<char> stcChaOprts({'#'});
	stack<double> stcDblValues;
	double dblValue = 0, dblNumA = 0, dblNumB = 0;
	string::size_type sizPosOfMidExp = 0;
	strMidExp = DropSpaceInStr(strMidExp) + '#';
	dblValue = stod(strMidExp, &sizPosOfMidExp);
	stcDblValues.push(dblValue);
	// TODO: deal with mid-expression
	while  (sizPosOfMidExp < strMidExp.size()) {
		// get top oprt in stack, compare with current oprt of midExp
		switch (GetPriority(stcChaOprts.top(), strMidExp[sizPosOfMidExp])) {
			case '>':
				/* value top oprt of stack and push result into stack
				 * sizPosOfMidExp remain unchanged to next comparation
				 */
				dblNumB = stcDblValues.top();
				stcDblValues.pop();
				dblNumA = stcDblValues.top();
				stcDblValues.pop();
				stcDblValues.push(ValueOf(dblNumA, dblNumB, stcChaOprts.top()));
				stcChaOprts.pop();
				continue;
			case '<':
				/* push current oprt of imdExp */
				stcChaOprts.push(strMidExp[sizPosOfMidExp]);
				++sizPosOfMidExp;
				break;
			case '=':
				/* '()' or '##', just pop it */
				stcChaOprts.pop();
				++sizPosOfMidExp;
				continue;
			default: /* TODO: error */ break;
		}
		if (strMidExp[sizPosOfMidExp] == '(')
			continue;
		// get value and push into stack
		dblValue = SubStr2Double(strMidExp, sizPosOfMidExp);
		stcDblValues.push(dblValue);
	}
	return stcDblValues.top();
}

int main(int argc, char **argv)
{
	const string midExpStr[] = {
		"1+2+3",
		"1+2*3",
		"1+2*(3+4*5+1)",
		"1*2-(3+4*5+1)",
		"1*2-(3+4/5/6)+7-8/9",
		"-1*2-(3+4/5/6)+7-8/9",
		"-1*2-(-3+4/5/6)+7-8/9",
		"-1+2-(-3+4/5/6)+7-8/9",
		"-1+2-((-3+4)/(5/6))+7-8/9",
		"-1+2-((-3+4)/2-(5/6)+3)+7-8/9",
		"-1+2*((-3+4)/2-(5/6)+3)+7-8/9",
		"-1+2/((-3+4)/2-(5/6)+3)+7-8/9",
		"-1/2/((-3+4)/2-(5/6)+3)+7-8/9",
		"-1/2/((-3+4)/2/(5/6)+3)+7-8/9",
		"-1/2/((-3+4)/(2/(5/6)+3)+7-8/9)",
		"1+2/(3+5)/5/6"
	};
	/* post expression:
	 * 123++			6
	 * 123*+			7
	 * 12345*1++*+			49
	 * 12*345*1++-			-22
	 * 12*345/6/+-789/-+		4.97778
	 * -12*345/6/+-789/-+		0.977778
	 * -12*-345/6/+-789/-+		6.97778
	 * -12-345/6/+-789/-++		9.97778
	 * -12-34+56//-789/-++		5.91111
	 * -12-34+2/56/-3+-789/-++	4.44444
	 * -12-34+2/56/-3+*789/-++	10.4444
	 * -12-34+2/56/-3+/789/-++	5.86111
	 * -12/-34+2/56/-3+/789/-+	5.92361
	 * -12/-34+2/56//3+/789/-+	5.97222
	 * -12/-34+256//3+/789/-+/	-0.0794118
	 * 1235+/5/6/+			1.00833
	 */
	for (auto const &str : midExpStr) {
		cout << ValueMidExp(str) << endl;
	}

	return 0;
}

