/* 2016.09.29 22:50
 * P_159
 */
#include <iostream>

char GRADE[] = {'A', 'B', 'C', 'D'};
enum {
	A,
	B,
	C,
	D
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	double score = random() % 50 + 50;
	char cScore;
	score > 90 ? 
		cScore = GRADE[A] :
	score > 80 ?
		cScore = GRADE[B] :
	score > 70 ? 
		cScore = GRADE[C] :
		cScore = GRADE[D];

	std::cout << score << ' ' << cScore;



	return 0;
}

