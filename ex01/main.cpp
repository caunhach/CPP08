#include "Span.hpp"

int main(void)
{
	Span	sp(20);

	try {
		sp.addNumber(1);
		sp.addNumber(3);
		sp.addNumber(-2);
		sp.addNumber(7);
		sp.addNumber(8);
		sp.addNumber(-3);
		sp.addNumber(-4);
		sp.addNumber(0);
		sp.addNumber(-10);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	sp.printVector();

	Span	sp2(10000);
	std::srand(time(NULL));
	try {
		for (int i = 0; i < 10000; i++)
		{
			int random = rand() % 10000;
			sp2.addNumber(random);
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	sp2.printVector();

	Span	sp3(100);
	std::vector<int>	v;
	std::srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		int random = rand() % 10000;
		v.push_back(random);
	}
	try {
		sp3.addNumber(v.begin(), v.end());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	sp3.printVector();
	return 0;
}