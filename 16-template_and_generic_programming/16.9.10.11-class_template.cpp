/* 2017.03.14 19:54
 * P_583
 *
 * the member template function will be instantiated only when using it by defualt !!!
 * for class template, compiler can't deduce the template type parameters which have to be specified !!!
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename elemType> class ListItem;
template <typename elemType> class List {
	public:
		List<elemType>();
		List<elemType>(const List<elemType>&);
		List<elemType>& operator=(const List<elemType>&);
		~List();
		//void insert(ListItem *ptr, elemType value);
		void insert(ListItem<elemType> *ptr, elemType value);
	private:
		//ListItem *fron, *end;
		ListItem<elemType> *fron, *end;
};

int main(int argc, char **argv)
{

	return 0;
}

