#ifndef THREAD_DATA_H
#define THREAD_DATA_H

#include <iostream>
#include <windows.h>

struct ThreadData {
    int* arr;
    int size;
    int* minVal;
    int* maxVal;
    double* avgVal;
};

#endif // THREAD_DATA_H
