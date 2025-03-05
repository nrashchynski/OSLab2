#include <clocale>
#include <iostream>
#include <windows.h>
#include "thread_functions.h"

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