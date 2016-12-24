/* 2016.12.23 21:16
 * P_369
 * !!!
 * arguments pattern: !!!
 *	alg(beg, end, othr_args);
 *	alg(beg, end, dest, othr_args);
 *	alg(beg, end, beg2, othr_args);
 *	alg(beg, end, beg2, end2, othr_args);
 *	'dest' could be:
 *		iterator of container: writing into very element
 *		inserter of container: insert into container
 *		ostream_iterator: writing into ostream
 * norms to name algorithms: !!!
 *	reload:
 *		unique(beg, end)
 *		unique(beg, end, comp)
 *	_if: rename instead of reload to avoid confuse due to the same numbers of arguments
 *		find(beg, ened, val)
 *		find_if(beg, ened, pred)
 *	_copy: redirect resorting elements to another space
 *		reverse(beg, end)
 *		reverse(beg, end, dest)
 *	both _if and _copy:
 *		remove_if(beg, end, pred)
 *		remove_copy_if(beg, end, dest, pred)
 *
 * Quiz1041:
 * replace(beg, end, old_val, new_val)
 *	replace old_val with new_val from beg to end
 * replace_if(beg, end, pred, new_val)
 *	replace with new_val if pred is true from beg to end
 * replace_copy(beg, end, dest, old_val, new_val)
 *	replace old_val with new_val from beg to end, output result to dest
 * replace_copy_if(beg, end, dest, pred, new_val)
 *	replace with new_val if pred is true from beg to end, output result to dest
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

