/* 2016.12.28 15:15
 * P_396
 * !!!
 * unordered associative container: !!!
 * head file: <unordered_map> <unordered_set>
 * operations:
 * c.bucket_count(): number of using buckets
 * c.max_bucket_count(): max number of buckets container could hold
 * c.bucket_size(n): number of elements of n-th bucket
 * c.bucket(key): return bucket which contains key
 * local_iterator:
 * const_local_iterator: iterator of elements(*it == pair<>)
 * c.load_factor(): float, average number of elements in buckets
 * c.max_load_factor(): load_factor() > max_load_factor(), auto add bucket
 * c.rehash(n): make bucket_count()<n && bucket_count()<size/max_load_factor()
 * c.reserve(n): make c to save n elements without rehash
 *
 * unordered associative contains using '==' to compare by default
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <typeinfo>

using namespace std;

class Sales_data {
	public:
		Sales_data(string const &str):isbn(str) {}
		string isbn;
};
size_t Hasher(Sales_data const &salesData)
{
	return hash<string>() (salesData.isbn);
}
bool CompareIsbn(Sales_data const &a, Sales_data const &b)
{
	return a.isbn == b.isbn;
}
void UnorderedEG()
{
	using UMSetSalesdata = unordered_multiset<Sales_data,
	      decltype(Hasher)*, decltype(CompareIsbn)*>;
	// 42 is capacity of bucket
	UMSetSalesdata bookstore(42, Hasher, CompareIsbn);
	Sales_data arrSalesdata[] = {Sales_data("a"), Sales_data("b")};
	bookstore.insert(begin(arrSalesdata), end(arrSalesdata));
	for (auto const &book : bookstore)
		cout << book.isbn << ' ';
	cout << endl;
	// output: b a

	unordered_map<string, int>::iterator it1;
	unordered_map<string, int>::local_iterator it2;
	cout << typeid(it1).name() << endl;
	cout << typeid(it2).name() << endl;
	cout << typeid(*it1).name() << endl;
	cout << typeid(*it2).name() << endl;
	/* output:
	 *	NSt8__detail14_Node_iteratorISt4pairIKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiELb0ELb1EEE
	 *	NSt8__detail15_Local_iteratorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_iENS_10_Select1stESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0ELb1EEE
	 *	St4pairIKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
	 *	St4pairIKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
	 */
}

int main(int argc, char **argv)
{
	UnorderedEG();

	return 0;
}

