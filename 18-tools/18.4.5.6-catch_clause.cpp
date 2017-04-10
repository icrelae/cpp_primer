/* 2017.04.10 20:44
 * P_689
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void CatchClauseEG()
{
	try {
	} catch (...) {
		// catch any type of exception
		throw;
		// rethrowing :
		// without exception-class obj, can be using only in catch;
		// here do some deals, then hand to upper catch
	}
}

int main(int argc, char **argv)
{
	//try {
	//} catch (exception) {
	//} catch (const runtime_error &re) {
	//} catch (overflow_error eobj) {
	//}

	try {
	} catch (overflow_error eobj) {
	} catch (const runtime_error &re) {
	} catch (exception) {
	}

	try {
	} catch (exception) {
	}

	// a
	class exceptionType { };
	try {
		exceptionType ex;
		throw(&ex);
	} catch (exceptionType *pte) {
	}
	try {
		throw exception();
	} catch (...) {
	}
	typedef int EXCPTYPE;
	try {
		throw 1;
	} catch (EXCPTYPE) {
	}

	return 0;
}

