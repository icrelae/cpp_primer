/* 2016.11.26 18:17
 * P_324
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ExtendString0(string name, string prefix, string suffix)
{
	return prefix + name + suffix;
}

string ExtendString1(string name, string prefix, string suffix)
{
	string::const_iterator itStr = name.begin();
	name.insert(itStr, prefix.begin(), prefix.end());
	name.append(suffix);
	return name;
}
string ExtendString2(string name, string prefix, string suffix)
{
	name.insert(name.begin(), prefix.begin(), prefix.end());
	name.insert(name.end(), suffix.begin(), suffix.end());
	return name;
}
string ExtendString3(string name, string prefix, string suffix)
{
	name.replace(0, 0, prefix);
	name.replace(name.size(), 0, suffix);
	return name;
}
int main(int argc, char **argv)
{
	cout << ExtendString0("Tma", "Mr.", " Jr.") << endl;
	cout << ExtendString1("Tma", "Mr.", " Jr.") << endl;
	cout << ExtendString2("Tma", "Mr.", " Jr.") << endl;
	cout << ExtendString3("Tma", "Mr.", " Jr.") << endl;

	return 0;
}

