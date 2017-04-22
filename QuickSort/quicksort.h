#pragma once

#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>

std::vector<int> genRandomArray(size_t size);

void showVectorInt(const std::vector<int> vector);

void quickSort(std::vector<int>::iterator l, std::vector<int>::iterator r);

void directInsertion(std::vector<int>::iterator l, std::vector<int>::iterator r);