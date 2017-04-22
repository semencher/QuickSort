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

void quickSort(std::vector<int>::iterator l, std::vector<int>::iterator r)
{
	if (l < r) {
		auto i = l;
		auto j = r - 1;
		int x = *i;
		while (i <= j) {
			for (; *i < x; ++i);
			for (; *j > x; --j);
			if (i <= j) {
				std::swap(*i, *j);
				++i;
				--j;
			}
		}
		if (i - l > 30) {
			quickSort(l, i);
		}
		else {
			directInsertion(l, i);
		}
		if (r - i > 30) {
			quickSort(i, r);
		}
		else {
			directInsertion(i, r);
		}
	}
}

void directInsertion(std::vector<int>::iterator l, std::vector<int>::iterator r)
{
	auto i = l + 1;
	auto N = r;
	while (i < N) {
		auto j = i - 1;
		int x = *i;
		do {
			if (j < l || *j <= x) {
				*(j + 1) = x;
				++i;
				break;
			}
			*(j + 1) = *(j);
			if (j != l) {
				--j;
			}
			else {
				*j = x;
				++i;
				break;
			}
		} while (true);
	}
}