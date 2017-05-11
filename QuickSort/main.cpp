#include <functional>
#include <chrono>

#include "quicksort.h"

int main()
{
	const size_t size = 1e6;
	std::vector<int> vector = genRandomArray(size);
	std::vector<int> vector_same = vector;

	std::chrono::time_point<std::chrono::high_resolution_clock> start, stop;
	start = std::chrono::high_resolution_clock::now();
	std::sort(vector_same.begin(), vector_same.end());
	stop = std::chrono::high_resolution_clock::now();
	std::cout << "StandartSort:\n";
	std::cout << "Size: " << size << ".\n";
	std::cout << (std::is_sorted(vector_same.begin(), vector_same.end()) ? "Ok!" : "No!") << "\n";
	std::cout << "Time: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << "ms.\n\n";

	start = std::chrono::high_resolution_clock::now();
	quickSort(vector.begin(), vector.end(), 4);
	stop = std::chrono::high_resolution_clock::now();
	std::cout << "MySort:\n";
	std::cout << "Size: " << size << ".\n";
	std::cout << (std::is_sorted(vector.begin(), vector.end()) ? "Ok!" : "No!") << "\n";
	std::cout << "Time: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << "ms.\n\n";

	int a = 0;
	std::cin >> a;
	return 0;
}