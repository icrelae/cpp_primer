/* 2016.12.28 13:11
 * P_394
 * map[key] will add key into map if key cannot be found
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> GetMap(string const &fileName)
{
	ifstream isMapFile(fileName);
	map<string, string> reflectMap;
	string key;
	while (isMapFile >> key) {
		string value;
		getline(isMapFile, value);
		// skip space and tab between key and value
		reflectMap[key] = value.substr(value.find_first_not_of(" \t"));
	}
	return reflectMap;
}

string TransformWord(map<string, string> const &reflectMap, string const &strKey)
{
	auto itPos = reflectMap.find(strKey);
	if (itPos != reflectMap.end())
		/* return reflectMap[strKey];
		 * error due to 'const map' and 'map[]' returning lvalue are conflict
		 */
		return itPos->second;
	else
		return strKey;
}

void TransformFile(string const &strFileOrg, string const &strFileMap)
{
	ifstream isFileOrg(strFileOrg);
	map<string, string> reflectMap = GetMap(strFileMap);
	string strLine;
	while (getline(isFileOrg, strLine)) {
		istringstream isLine(strLine);
		string word;
		cout << strLine << endl;
		isLine >> word;
		cout << TransformWord(reflectMap, word);
		while (isLine >> word) {
			word = TransformWord(reflectMap, word);
			cout << ' ' << word;
		}
		cout << endl;
	}
}

int main(int argc, char **argv)
{
	string strMapName("/tmp/map");
	string strOrgName("/tmp/txt");
	TransformFile(strOrgName, strMapName);

	return 0;
}
/* /tmp/map:
 *	brb be right back
 *	k	okay?
 *	y	why
 *	r	are
 *	u	you
 *	pic	picture
 *	thk	thanks!
 *	l8r	later
 * /tmp/txt:
 *	where r u
 *	y dont u send me a pic
 hk l8r brb
 * output:
 *	where r u
 *	where are you
 *	y dont u send me a pic
 *	why dont you send me a picture
 *	k thk l8r brb
 *	okay? thanks! later be right back
 */

