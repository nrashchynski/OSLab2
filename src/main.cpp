#include <iostream>
#include <clocale>
#include <Windows.h>

int size;
int* arr;
int minVal, maxVal;
double avgVal;

DWORD WINAPI findMinMax(LPVOID lpParam) {
	maxVal = arr[0];
	minVal = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < minVal) {
			minVal == arr[i];
		}
		if (arr[i] > maxVal) {
			maxVal == arr[i];
		}
		Sleep(7);
	}
	std::cout << "Наибольший элемент массива: " << maxVal << '\n';
	std::cout << "Наименьший элемент массива: " << minVal << '\n';
	return 0;
}

DWORD WINAPI calculateAverage(LPVOID lpParam) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
		Sleep(12);
	}
	avgVal = (double)sum / size;
	return 0;
}


int main() {
	setlocale(LC_ALL, "ru");

	std::cout << "Введите размерность массива: ";
	std::cin >> size;
	std::cout << '\n';
	arr = new int[size];

	std::cout << "Введите " << size << " элементов массива:\n";
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}
	std::cout << '\n';

	HANDLE hThreadMinMax = CreateThread(NULL, 0, findMinMax, NULL, 0, NULL);
	HANDLE hThreadAverage = CreateThread(NULL, 0, calculateAverage, NULL, 0, NULL);

	WaitForSingleObject(hThreadMinMax, INFINITE);
	WaitForSingleObject(hThreadAverage, INFINITE);

	CloseHandle(hThreadMinMax);
	CloseHandle(hThreadAverage);

	for (int i = 0; i < size; i++) {
		if (arr[i] == minVal || arr[i] == maxVal) {
			arr[i] = (int)avgVal;
		}
	}

	std::cout << "Обновленный массив: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';

	delete[] arr;

	return 0;
}