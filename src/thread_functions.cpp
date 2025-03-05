#include "thread_functions.h"

DWORD WINAPI findMinMax(LPVOID lpParam) {
	ThreadData* data = static_cast<ThreadData*>(lpParam);
	int* arr = data->arr;
	int& minVal = *data->minVal;
	int& maxVal = *data->maxVal;

	minVal = INT_MAX;
	maxVal = INT_MIN;

	for (int i = 0; i < data->size; i++) {
		if (arr[i] < minVal) {
			minVal = arr[i];
		}
		if (arr[i] > maxVal) {
			maxVal = arr[i];
		}
		Sleep(7);
	}
	return 0;
}

DWORD WINAPI calculateAverage(LPVOID lpParam) {
	ThreadData* data = static_cast<ThreadData*>(lpParam);
	int* arr = data->arr;
	double& avgVal = *data->avgVal;

	int sum = 0;
	for (int i = 0; i < data->size; i++) {
		sum += arr[i];
		Sleep(12);
	}
	avgVal = (double)sum / data->size;
	return 0;
}

void replaceMinMaxWithAverage(int* array, int size, int minElement, int maxElement, double averageValue) {
	for (int i = 0; i < size; i++) {
		if (array[i] == minElement || array[i] == maxElement) {
			array[i] = (int)averageValue;
		}
	}
}