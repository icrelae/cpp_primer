/* 2017.03.25 21:42
 * P_624
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

template<typename T, typename... Args>
shared_ptr<T> makeShared(Args&&... args)
{
	shared_ptr<T> ret(new T(std::forward<Args>(args)...));
	return ret;
}

int main(int argc, char **argv)
{
	shared_ptr<string> strPtr = makeShared<string>(10, 'c');
	strPtr = makeShared<string>("asdf");

	return 0;
}

