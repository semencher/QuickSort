#pragma once

#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <future>

std::vector<int> genRandomArray(size_t size);

void showVectorInt(const std::vector<int> vector);

template <typename RandomIt, typename Compare = std::less<>>
void quickSort(RandomIt first, RandomIt last, size_t tCount, Compare comp = Compare())
{
	if (first < last) {
		RandomIt i = first;
		RandomIt j = last - 1;
		auto x = *i;
		while (i <= j) {
			for (; comp(*i, x); ++i);
			for (; comp(x, *j); --j);
			if (i <= j) {
				std::swap(*i, *j);
				++i;
				--j;
			}
		}
		if (i - first > 30) {
			if (tCount > 1) {
				--tCount;
				std::async(std::launch::async, quickSort<RandomIt, Compare>,
					first, i, tCount, comp);
			}
			else {
				quickSort(first, i, tCount, comp);
			}
		}
		else {
			directInsertion(first, i, comp);
		}
		if (last - i > 30) {
			quickSort(i, last, tCount, comp);
		}
		else {
			directInsertion(i, last, comp);
		}
	}
}

template <typename RandomIt, typename Compare = std::less<>>
void directInsertion(RandomIt first, RandomIt last, Compare comp = Compare())
{
	RandomIt i = first + 1;
	RandomIt N = last;
	while (i < N) {
		RandomIt j = i - 1;
		auto x = *i;
		do {
			if (j < first || !comp(x, *j)) {
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