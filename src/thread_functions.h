#ifndef THREAD_FUNCTIONS_H
#define THREAD_FUNCTIONS_H 

#include "thread_data.h"

DWORD WINAPI findMinMax(LPVOID lpParam);
DWORD WINAPI calculateAverage(LPVOID lpParam);
void replaceMinMaxWithAverage(int* array, int size, int minElement, int maxElement, double averageValue);

#endif