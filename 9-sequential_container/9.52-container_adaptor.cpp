/* 2016.11.29 22:32
 * P_331
 * !!!
 * adaptor: stack, queue, priority_queue !!!
 * adaptro can't random access
 * by default, stack and queue based on deque, priority_queue based on vector
 * Adaptor::size_type
 * Adaptor::value_type
 * Adaptor::container_type
 * Adaptor adp;
 * Adaptor adp(vecInt);
 * adb.empty();
 * adb.size()
 * adpA.swap(adpB);
 * swap(adpA, adpB)
 * for stack: !!!
 * stc.pop(), stc.push(item), stc.emplace(args), stc.top()
 * for queue and priority_queue: !!!
 * q.pop(): return first of queue or highest priority element of priority_queue
 * q.front()
 * q.back(): return the last, only for queue
 * q.top(): return highest priority element, only for priority_queue
 * q.push(item)
 * q.emplace(args)
 */
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

priority_queue<int> a;
#define DEBUG	1
#define _DEBSHOW(item, newLine)	\
	do {			\
		cout << "(debug) " << #item << ": " << item;	\
		if (newLine != 0)				\
			cout << endl;				\
		else						\
			cout << flush;				\
	} while (0)
#define DEBSHOW(item, newLine)	

void DefineStackEG()
{
	deque<int> deqInt;
	vector<int> vecInt;
	stack<int> stkIntDeq(deqInt);	// by default, using deque
	stack<int, vector<int>> stkIntVec(vecInt);	// using vector
}
double SubStr2Num(const string &str, string::size_type &pos)
{
	string::size_type posOri = pos;
	double num = stod(str.substr(pos), &pos);
	pos += posOri;
	return num;
}
string DropSpace(string exp)
{
	while (exp.find(' ') != string::npos)
		exp.erase(exp.find(' '), 1);
	return exp;
}
bool MidExp2PostExp(const string midExpStr, queue<char> &queChaPostExp,
		queue<double> &queDblValue)
{
	stack<char> stcChaOperator;
	string::size_type iMidExp = 0;
	while (iMidExp < midExpStr.size()) {
		DEBSHOW(iMidExp, 1);
		if (!stcChaOperator.empty() && stcChaOperator.top() == ')') {
			stcChaOperator.pop();
			if (!stcChaOperator.empty() && 
					(stcChaOperator.top() == '/')) {
				queChaPostExp.push(stcChaOperator.top());
				stcChaOperator.pop();
			}
		}
		else if (midExpStr[iMidExp] != '(') {
			queChaPostExp.push(' ');
			double dNum= SubStr2Num(midExpStr, iMidExp);
			DEBSHOW(dNum, 1);
			queDblValue.push(dNum);
			//queDblValue.push(SubStr2Num(midExpStr, iMidExp));
			if (!stcChaOperator.empty() &&
					(stcChaOperator.top() == '/')) {
				queChaPostExp.push(stcChaOperator.top());
				stcChaOperator.pop();
			}
			if (iMidExp >= midExpStr.size())
				continue;
		}
		DEBSHOW(iMidExp, 1);
		switch (midExpStr[iMidExp]) {
			case '+':
				// no break, same with '-'
			case '-':
				if (!stcChaOperator.empty() &&
						stcChaOperator.top() == '-') {
					queChaPostExp.push(stcChaOperator.top());
					stcChaOperator.pop();
				}
				while ((!stcChaOperator.empty()) && 
						(stcChaOperator.top() == '*' || 
						stcChaOperator.top() == '/')) {
					queChaPostExp.push(stcChaOperator.top());
					stcChaOperator.pop();
				}
				stcChaOperator.push(midExpStr[iMidExp]);
				break;
			case '*':
				// no break, same with '/'
			case '/':
				stcChaOperator.push(midExpStr[iMidExp]);
				break;
			case '(':
				stcChaOperator.push(midExpStr[iMidExp]);
				break;
			case ')':
				while (stcChaOperator.top() != '(') {
					queChaPostExp.push(stcChaOperator.top());
					stcChaOperator.pop();
				}
				stcChaOperator.pop();
				stcChaOperator.push(')');
				break;
			default:
				// TODO: error
				DEBSHOW(midExpStr[iMidExp], 1);
				cerr << __FILE__ << ':' << __LINE__;
				cerr << " unexpect operator" << endl;
				return false;
		}
		++iMidExp;
	}
	if (stcChaOperator.top() == ')')
		stcChaOperator.pop();
	while (!stcChaOperator.empty()) {
		queChaPostExp.push(stcChaOperator.top());
		stcChaOperator.pop();
	}
#if DEBUG
	queue<char> _queChaPostExp = queChaPostExp;
	queue<double> _queDblValue = queDblValue;
	while (!_queChaPostExp.empty()) {
		if (_queChaPostExp.front() == ' ') {
			cout << _queDblValue.front();
			_queDblValue.pop();
			_queChaPostExp.pop();
		} else {
			cout << _queChaPostExp.front();
			_queChaPostExp.pop();
		}
	}
	cout << endl;
#endif
	return true;
}
bool IsValidOperator(char const chaOperator)
{
	switch (chaOperator) {
		case '+':	// no break
		case '-':	// no break
		case '*':	// no break
		case '/':	// no break
			return true;
		default:
			return false;
	}
}
double ValueOf(double const a, double const b, char const chaOperator)
{
	double result = 0;
	switch (chaOperator) {
		case '+':
			DEBSHOW(a+b, 0);
			result = a + b;
			break;
		case '-':
			DEBSHOW(a-b, 0);
			result = a - b;
			break;
		case '*':
			DEBSHOW(a*b, 0);
			result = a * b;
			break;
		case '/':
			DEBSHOW(a/b, 0);
			result = a / b;
			break;
		default:
			// TODO: error
			cerr << __FILE__ << ':' << __LINE__;
			cerr << " unexpect operator" << endl;
			break;
	}
	return result;
}
double ValuePostExp(queue<char> queChaPostExp, queue<double> queDblValue)
{
	stack<double> stcDblValue;
	while (!queChaPostExp.empty()) {
		char chOprtOfPostExp = queChaPostExp.front();
		queChaPostExp.pop();
		if (chOprtOfPostExp == ' ') {
			stcDblValue.push(queDblValue.front());
			queDblValue.pop();
			continue;
		}
		double b = stcDblValue.top();
		stcDblValue.pop();
		double a = stcDblValue.top();
		stcDblValue.pop();
		if (IsValidOperator(chOprtOfPostExp) == true)
			stcDblValue.push(ValueOf(a, b, chOprtOfPostExp));
		else {
			// TODO: error
			cerr << __FILE__ << ':' << __LINE__;
			cerr << " value post expression error" << endl;
		}
	}
	return stcDblValue.top();
}
double ValueMidExp(string const strMidExp)
{
	queue<char> queChaPostExp;
	queue<double> queDblValue;
	MidExp2PostExp(strMidExp, queChaPostExp, queDblValue);
	return ValuePostExp(queChaPostExp, queDblValue);
}
double Calculate(const string midExpStr)
{
	queue<char> postExp;
	stack<char> operators;
	queue<double> value;
	string::size_type iMidExp = 0;
	while (iMidExp < midExpStr.size()) {
		DEBSHOW(iMidExp, 1);
		if (!operators.empty() && operators.top() == ')') {
			operators.pop();
			if (!operators.empty() && (operators.top() == '/')) {
				postExp.push(operators.top());
				operators.pop();
			}
		}
		else if (midExpStr[iMidExp] != '(') {
			postExp.push(' ');
			double dNum= SubStr2Num(midExpStr, iMidExp);
			DEBSHOW(dNum, 1);
			value.push(dNum);
			//value.push(SubStr2Num(midExpStr, iMidExp));
			if (!operators.empty() && (operators.top() == '/')) {
				postExp.push(operators.top());
				operators.pop();
			}
			if (iMidExp >= midExpStr.size())
				continue;
		}
		DEBSHOW(iMidExp, 1);
		switch (midExpStr[iMidExp]) {
			case '+':
				// no break, same with '-'
			case '-':
				if (!operators.empty() &&
						operators.top() == '-') {
					postExp.push(operators.top());
					operators.pop();
				}
				while ((!operators.empty()) && 
						(operators.top() == '*' || 
						operators.top() == '/')) {
					postExp.push(operators.top());
					operators.pop();
				}
				operators.push(midExpStr[iMidExp]);
				break;
			case '*':
				// no break, same with '/'
			case '/':
				operators.push(midExpStr[iMidExp]);
				break;
			case '(':
				operators.push(midExpStr[iMidExp]);
				break;
			case ')':
				while (operators.top() != '(') {
					postExp.push(operators.top());
					operators.pop();
				}
				operators.pop();
				operators.push(')');
				break;
			default:
				// TODO: error
				DEBSHOW(midExpStr[iMidExp], 1);
				cerr << __FILE__ << ':' << __LINE__;
				cerr << " unexpect operator" << endl;
				break;
		}
		++iMidExp;
	}
	if (operators.top() == ')')
		operators.pop();
	while (!operators.empty()) {
		postExp.push(operators.top());
		operators.pop();
	}
#if DEBUG
	queue<char> _postExp = postExp;
	queue<double> _value = value;
	while (!_postExp.empty()) {
		if (_postExp.front() == ' ') {
			cout << _value.front();
			_value.pop();
			_postExp.pop();
		} else {
			cout << _postExp.front();
			_postExp.pop();
		}
	}
	cout << endl;
#endif
	stack<double> valStc;
	while (!postExp.empty()) {
		char chOfPostExp = postExp.front();
		postExp.pop();
		if (chOfPostExp == ' ') {
			valStc.push(value.front());
			value.pop();
			continue;
		}
		double b = valStc.top();
		valStc.pop();
		double a = valStc.top();
		valStc.pop();
		switch (chOfPostExp) {
			case '+':
				valStc.push(a+b);
				DEBSHOW(a+b, 0);
				break;
			case '-':
				valStc.push(a-b);
				DEBSHOW(a-b, 0);
				break;
			case '*':
				valStc.push(a*b);
				DEBSHOW(a*b, 0);
				break;
			case '/':
				valStc.push(a/b);
				DEBSHOW(a/b, 0);
				break;
			default:
				// TODO: error
				cerr << __FILE__ << ':' << __LINE__;
				cerr << " unexpect operator";
				break;
		}
	}
	return valStc.top();
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
		DEBSHOW(str, 1);
		cout << Calculate(str) << endl;
	}
	for (auto const &str : midExpStr) {
		DEBSHOW(str, 1);
		cout << ValueMidExp(str) << endl;
	}

	return 0;
}

