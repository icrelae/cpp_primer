/* 2016.11.24 21:41
 * P_320
 * !!!
 * reserve()/capacity()/shrink_to_fit(): !!!
 * reserve()/capacity() are available for vector/string
 * shrink_to_fit() is available for vector/string/deque
 * c.reserve(n): reallocate space that can hold n elements at least, if n<c.capacity() do nothing
 * c.capacity(): return maximum size of container if not reallocate
 * c.shrink_to_fit(): shrink container to c.size()
 *
 * 1)	list have no capacity() because its not a sequent space, 
 *	so it never reallocate space since it have no upper limit of content,
 *	there is no need to know capacity of a list.
 * 2)	array have no capacity() because the capacity of an array is constant with its size().
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{

	return 0;
}

