/* 2016.12.23 21:16
 * P_367
 * !!!
 * operations of 5 different iterators: !!!
 * input iterator:
 *	++it, it++, =*it, it->, ==, !=
 *	available for single pass algorithm
 *	EG: argument of find() and accumulate(), istream_iterator
 * output iterator:
 *	++it, it++, *it=
 *	can assign it only once
 *	available for single pass algorithm
 *	EG: 3rd argument of copy(), ostream_iterator
 * forward iterator:
 *	++it, it++, =*it, *it=, it->, ==, !=
 *	can assign it many times
 *	available for many passes algorithm
 *	EG: argument of replace(), iterator of forward_list
 * bidirectional iterator:
 *	++it, it++, =*it, *it=, it->, ==, !=, --it, it--
 *	can assign it many times
 *	available for many passes algorithm
 *	EG: argument of reverse(), all container support iterator meeting
 *		requirements of bidirectional-iterator except forward_list
 * random-access iterator:
 *	++it, it++, =*it, *it=, it->, ==, !=, --it, it--
 *	<, >, <=, >=, +, -, +=, -=, itA-itB, it[n]
 *	can assign it many times
 *	available for many passes algorithm
 *	EG: argument of sort(), iterator of array|deque|string|vector,
 *		begin(int[])|end(int[])
 */
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{

	return 0;
}

