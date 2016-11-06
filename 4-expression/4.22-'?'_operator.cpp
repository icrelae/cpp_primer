/* 2016.09.24 21:55
 * P_135
 */
#include <iostream>

void Method1(int grade)
{
	std::cout << grade << ' ' << ((grade > 75) ?  "high pass" :
			(grade > 60) ? "low pass" : "fail");
	std::cout << std::endl;
}
void Method2(int grade)
{
	if (grade > 75)
		std::cout << grade << ' ' << "high pass";
	else if (grade > 60)
		std::cout << grade << ' ' << "low pass";
	else
		std::cout << grade << ' ' << "fail";
	std::cout << std::endl;
}
int main(int argc, char **argv)
{
	srand(time(NULL));
	int grade = random() % 100;
	Method1(grade);
	Method2(grade);

	return 0;
}

