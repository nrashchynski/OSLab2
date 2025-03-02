#include <iostream>
#include <clocale>
#include <windows.h>
#include "thread_data.h"


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
	std::cout << "Наибольший элемент массива: " << maxVal << '\n';
	std::cout << "Наименьший элемент массива: " << minVal << '\n';
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


int main() {
	setlocale(LC_ALL, "ru");

	try {
		int size;
		std::cout << "Введите размерность массива: ";
		std::cin >> size;
		std::cout << '\n';

		if (size <= 0) {
			throw "Ошибка: Размер массива должен быть положительным числом.";
		}
		int* arr = new int[size];

		std::cout << "Введите " << size << " элементов массива:\n";
		for (int i = 0; i < size; ++i) {
			std::cin >> arr[i];
		}
		std::cout << '\n';

		int minVal = INT_MAX;
		int maxVal = INT_MIN;
		double avgVal = 0.0;

		ThreadData threadData = { arr, size, &minVal, &maxVal, &avgVal };

		HANDLE hThreadMinMax = CreateThread(NULL, 0, findMinMax, &threadData, 0, NULL);
		if (hThreadMinMax == NULL) {
			delete[] arr;
			throw "Ошибка создания потока MinMaxThread.";
		}
		HANDLE hThreadAverage = CreateThread(NULL, 0, calculateAverage, &threadData, 0, NULL);
		if (hThreadAverage == NULL) {
			CloseHandle(hThreadMinMax);
			delete[] arr;
			throw "Ошибка создания потока AverageThread.";
		}

		WaitForSingleObject(hThreadMinMax, INFINITE);
		WaitForSingleObject(hThreadAverage, INFINITE);

		replaceMinMaxWithAverage(arr, size, minVal, maxVal, avgVal);

		std::cout << "Минимальный элемент: " << minVal << std::endl;
		std::cout << "Максимальный элемент: " << maxVal << std::endl;
		std::cout << "Среднее значение: " << avgVal << std::endl;
		std::cout << "Обновленный массив: ";
		for (int i = 0; i < size; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;

		CloseHandle(hThreadMinMax);
		CloseHandle(hThreadAverage);

		delete[] arr;
	}
	catch (const char* e) {
		std::cerr << "Ошибка: " << e << std::endl;
		return 1;
	}

	return 0;
}