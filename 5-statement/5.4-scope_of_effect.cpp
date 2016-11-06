/* 2016.09.29 22:41
 * P_156
 */
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	char *word = NULL;
	std::string s;

	// iter need initialize
	while (std::string::iterator iter != s.end()) { }

	while (bool status = s.find(word)) { }
	// status not in scope of effect
	if (!status) {}

	return 0;
}

