/* 2016.09.27 23:41
 * P_155
 * if abs(a-b) > 3, sum = abs(a-b)
 * else, sum = 3;
 */
#include <iostream>

int main(int argc, char **argv)
{
	srand(time(NULL));
	int a = random() % 10, b = random() % 10;
	std::cout << a << ' ' << b << std::endl;
	int sum = ({
			decltype(a) _tmpa = a;
			decltype(b) _tmpb = b;
			abs(_tmpa-_tmpb) > 3 ?
				({
				 std::cout << "a-b > 3" << std::endl;
				 abs(_tmpa-_tmpb);}) : 
				({
				 std::cout << "a-b <= 3" << std::endl;
				 3;
				 });
	});
	std::cout << sum;

	return 0;
}
