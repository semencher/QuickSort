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
	if (last - first <= 30) {
		directInsertion(first, last, comp);
		return;
	}
	RandomIt i = first;
	RandomIt j = last - 1;
	auto x = *(i + (j - i) / 2);
	while (i <= j) {
		for (; comp(*i, x); ++i);
		for (; comp(x, *j); --j);
		if (i <= j) {
			std::swap(*i, *j);
			++i;
			--j;
		}
	}
	if (tCount > 1) {
		int tCountLeft = std::ceil((tCount - 1) / static_cast<double>(2));
		std::future<void> f = std::async(std::launch::async, quickSort<RandomIt, Compare>,
			first, i, tCountLeft, comp);
		tCount = tCount - tCountLeft;
		quickSort(i, last, tCount, comp);
	}
	else {
		quickSort(first, i, tCount, comp);
		quickSort(i, last, tCount, comp);
	}
}

template <typename RandomIt, typename Compare = std::less<>>
void directInsertion(RandomIt first, RandomIt last, Compare comp = Compare())
{
	RandomIt i = first + 1;
	while (i < last) {
		RandomIt j = i - 1;
		auto x = *i;
		do {
			if (!comp(x, *j)) {
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