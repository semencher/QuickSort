#pragma once

#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>

std::vector<int> genRandomArray(size_t size);

void showVectorInt(const std::vector<int> vector);

template <typename RandomIt>
void quickSort(RandomIt first, RandomIt last)
{
	if (first < last) {
		RandomIt i = first;
		RandomIt j = last - 1;
		auto x = *i;
		while (i <= j) {
			for (; *i < x; ++i);
			for (; *j > x; --j);
			if (i <= j) {
				std::swap(*i, *j);
				++i;
				--j;
			}
		}
		if (i - first > 30) {
			quickSort(first, i);
		}
		else {
			directInsertion(first, i);
		}
		if (last - i > 30) {
			quickSort(i, last);
		}
		else {
			directInsertion(i, last);
		}
	}
}

template <typename RandomIt>
void directInsertion(RandomIt first, RandomIt last)
{
	RandomIt i = first + 1;
	RandomIt N = last;
	while (i < N) {
		RandomIt j = i - 1;
		auto x = *i;
		do {
			if (j < first || *j <= x) {
				*(j + 1) = x;
				++i;
				break;
			}
			*(j + 1) = *(j);
			if (j != first) {
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