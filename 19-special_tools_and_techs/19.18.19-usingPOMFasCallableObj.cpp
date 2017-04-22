/* 2017.04.22 16:37
 * P_746
 */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

// using pointer of member func as callable obj
void EG()
{
	vector<string> svec{"a", "s", "d", "f"};

	// invalid
	//find_if(svec.begin(), svec.end(), &string::empty);
	
	// using 'function'
	function<bool (const string&)> fcn = &string::empty;
	find_if(svec.begin(), svec.end(), fcn);

	// using 'mem_fn'
	auto f = mem_fn(&string::empty);
	f(*svec.begin());	// call 'empty()' with 'svec.begin().empty()'
	f(&svec[0]);		// call 'empty()' with 'svec[0]->empty()'
	find_if(svec.begin(), svec.end(), mem_fn(&string::empty));

	// using 'bind'
	auto f1 = bind(&string::empty, _1);
	f1(*svec.begin());	// call 'empty()' with 'svec.begin().empty()'
	f1(&svec[0]);		// call 'empty()' with 'svec[0]->empty()'
	find_if(svec.begin(), svec.end(), bind(&string::empty, _1));
}

void Ex18()
{
	vector<string> svec{"a", "", "", "f"};
	cout << count_if(svec.begin(), svec.end(), function<bool (const string&)>(&string::empty)) << endl;
	// output: 2
	
	vector<int> sint{1, 2, 3, 4, 5, 6, 7};
	cout << *find_if(sint.begin(), sint.end(),
			[] (const int &i) {
				return i > 5;
			});
	// output: 6
}

int main(int argc, char **argv)
{
	Ex18();

	return 0;
}

