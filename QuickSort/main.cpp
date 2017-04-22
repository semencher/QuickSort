#include "quicksort.h"
#include <functional>

int main()
{
	const size_t size = 100000;
	std::vector<int> vector = genRandomArray(size);
	quickSort(vector.begin(), vector.end());
	std::cout << "Size: " << size << ".\n";
	std::cout << (std::is_sorted(vector.begin(), vector.end()) ? "Ok!" : "No!") << "\n";

	int a = 0;
	std::cin >> a;
	return 0;
}