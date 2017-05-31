/* 2016.11.20 16:13
 * P_312
 * !!!
 * forwad_list don't have pop_back !!!
 * vector/string don't have pop_front !!!
 * delete element: !!!
 * c.pop_back() delete tail element; return void; if c is empty, behaviour undefined
 * c.pop_front() delete haed element; return void; if c is empty, behaviour undefined
 * c.erase(itPos) delete element pointed by itPos; return iterator pointed to next element; if itPos=c.end(), behaviour undefined
 * c.erase(itPosBeg, itPosEnd) delete elements from itPosBeg to itPosEnd(exclude itPosEnd); return iterator point to next element of itPosEnd
 * c.remove([itBeg, itEnd, ]val) delete element equal to 'val'
 * c.remove_if([itBeg, itEnd, ], op) delete if 'op' returns 'true'
 * c.clear() empty container, return void
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> vec{0, 1, 2, 3, 4, 5};
	vector<int>::const_iterator it0 = vec.begin()+1;
	vector<int>::const_iterator it1 = vec.begin()+1;
	// erase from it0 to it1, exclude it1 !!!
	vec.erase(it0, it1);
	for (const auto it : vec)
		cout << it << ' ';

	return 0;
}

