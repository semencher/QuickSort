#include "quicksort.h"

std::vector<int> genRandomArray(size_t size)
{
	std::vector<int> result(size);
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::generate(result.begin(), result.end(), std::rand);
	return result;
}

void showVectorInt(const std::vector<int> vector)
{
	auto print = [](const int& n) { std::cout << " " << n; };
	std::for_each(vector.begin(), vector.end(), print);
	std::cout << "\n";
}