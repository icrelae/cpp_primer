#include <vector>
class Example {
	public:
		//static double rate = 6.5;
		static double rate;
		//static const int vecSize = 29;
		static constexpr int vecSize = 29;
		//static std::vector<double> vec(vecSize);
		static std::vector<double> vec;
		int Foo();
};
