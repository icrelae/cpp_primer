/* 2016.11.15 21:19
 * P_304
 * !!!
 * 1) assign only available for seq_container !!!
 * 2) useing swap(a, b) rather than a.swap(b), 
 *	because the former is more efficient in generic programming !!!
 * 3) all iterator and pointer of a string will be invalidate by swap(0, 1) accoding the book,
 *	but actually they are not (g++ 6.2.1). it0 point to original site after swap(0, 1), now is 1.
 * 4) time of swapping array are proportional to its size as opposed to other seq-containers that cost constant time, 
 *	because swap array doing really exchange to each elements of array, so *it0 is 1 after swap(0, 1) !!!
 * 5) for other seq-container except string and array, *it0 will still be 0 after swap(0, 1) !!!
 */
#include <iostream>
#include <vector>
#include <array>
#include <list>

using namespace std;

void Assign()
{
	char str[] = "asdfg";
	vector<string> vecStr;
	list<char *> listCharPt{str, str};
	// two type of assign !!!
	vecStr.assign(3, "12345");
	for (auto str : vecStr)
		cout << str << endl;
	vecStr.assign(listCharPt.begin(), listCharPt.end());
	for (auto str : vecStr)
		cout << str << endl;
	vecStr[0] = "12345";
	for (auto str : vecStr)
		cout << str << endl;
}
void SwapArray()
{
	array<int, 3> arr0 = {0, 0, 0};
	array<int, 3> arr1 = {1, 1, 1};
	array<int, 3>::iterator itArr = arr0.begin();
	swap(arr0, arr1);
	cout << *itArr << endl;		// output: 1
}
void SwapString()
{
	string str0 = "000";
	string str1 = "111111";
	string::iterator itStr = str0.begin();
	swap(str0, str1);
	cout << *itStr << endl;		// output: 1
}
void SwapVectorString()
{
	vector<string> vecStr0 = {"00", "00"};
	vector<string> vecStr1 = {"11", "11"};
	vector<string>::iterator itVecStr = vecStr0.begin();
	swap(vecStr0, vecStr1);
	cout << *itVecStr << endl;	// output: 00
}
void SwapVectorInt()
{
	vector<int> vecInt0 = {0, 0};
	vector<int> vecInt1 = {1, 1};
	vector<int>::iterator itVecInt = vecInt0.begin();
	swap(vecInt0, vecInt1);
	cout << *itVecInt << endl;	// output: 0
}
int main(int argc, char **argv)
{
	Assign();
	SwapArray();
	SwapString();
	SwapVectorString();
	SwapVectorInt();

	return 0;
}

