 ## Лабораторная работа №2 
 Тема: «Создание потоков».
 Задача. Написать программу для консольного процесса, который состоит из трех потоков: main,
 min_max и average.
 Поток main должен выполнить следующие действия:
 1. Создать массив целых чисел, размерность и элементы которого вводятся с консоли.
 2. Создать потоки min_max и average.
 3. Дождаться завершения потоков min_max и average.
 4. Заменить максимальный и минимальный элементы массива на среднее значение элементов
 массива. Вывести полученные результаты на консоль.
 5. Завершить работу.
 Поток min_max должен выполнить следующие действия:
 1. Найти минимальный и максимальный элементы массива и вывести их на консоль. После
 каждого сравнения элементов «спать» 7 миллисекунд.
 2. Завершить свою работу.
 Поток average должен выполнить следующие действия:
 1. Найти среднее арифметическое значение элементов массива и вывести его на консоль.
 После каждой операции суммирования элементов «спать» 12 миллисекунд.
 2. Завершить свою работу.
 Примечания.
 1. Для ожидания завершения работы потоков min_max и average использовать функцию:
 DWORD WaitForSingleObject(
 HANDLE
 hHandle,
 DWORD dwMilliseconds
 );
 // дескриптор объекта
 // интервал ожидания в миллисекундах
 где второй параметр установить равным INFINITE. Например
 WaitForSingleObject(hAverage, INFINITE);
 Здесь hAverage – дескриптор потока average.
 2. Для засыпания использовать функцию:
 VOID Sleep(
 DWORD
 );
 Например,
 Sleep(12);
