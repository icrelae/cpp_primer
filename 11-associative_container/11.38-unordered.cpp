/* 2016.12.24 14:10
 * P_396
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

using UMapStrSiz = unordered_map<string, size_t>;
UMapStrSiz CountWords(vector<string> vecStr)
{
	UMapStrSiz mapWords;
	set<char> punctuations({',', '.', ';'});
	for (auto &str : vecStr) {
		for (auto &ch : str) {
			ch = tolower(ch);
		}
		for (auto &punc : punctuations) {
			str.erase(find(str.begin(), str.end(), punc), str.end());
		}

		++mapWords[str];
	}
	return mapWords;
}

void CountWordsEG()
{
	vector<string> vecStr({"a.", "b,", "A", "a"});
	UMapStrSiz mapWords = CountWords(vecStr);
	for (auto const word : mapWords)
		cout << word.first << ' ' << word.second << ' ';
	// output: a 3 b 1 
}

using UMapStrStr = unordered_map<string, string>;
UMapStrStr GetMap(string const &fileName)
{
	ifstream isMapFile(fileName);
	UMapStrStr reflectMap;
	string key;
	while (isMapFile >> key) {
		string value;
		getline(isMapFile, value);
		// skip space and tab between key and value
		string::size_type pos = value.find_first_not_of(" \t");
		if (pos != string::npos)
			value = value.substr(pos);
		else
			value = key;
		reflectMap[key] = value;
	}
	return reflectMap;
}

string TransformWord(UMapStrStr const &reflectMap, string const &strKey)
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
	UMapStrStr reflectMap = GetMap(strFileMap);
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

void TransformFileEG()
{
	string strMapName("/tmp/map");
	string strOrgName("/tmp/txt");
	TransformFile(strOrgName, strMapName);
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
}

int main(int argc, char **argv)
{
	CountWordsEG();
	TransformFileEG();
	return 0;
}
