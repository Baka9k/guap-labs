#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;


int countZeroElements(float *arr, int n) {
    // Считает нулевые элементы в массиве
    int counter = 0;
    for(int i = 0; i < n; ++i)
        if(arr[i] == 0)
            ++counter;
    return counter;
}

float getSumAfterMin(float *arr, int n, bool *flag) {
    // Возвращает сумму элементов массива, находящихся
    //   после его минимального элемента
    int minElementIndex = 0;
    float sum = 0;

    // Найти индекс минимального элемента
    for(int i = 0; i < n; ++i) {
        if(arr[minElementIndex] > arr[i]) {
            minElementIndex = i;
        }
    }
    if (minElementIndex == n-1) *flag = true;
    
    // Найти сумму
    for(int i = minElementIndex + 1; i < n; ++i)
        sum += arr[i];
    
    return sum;
}

void sortArray(float *arr, int n) {
    for(int i = (n - 1); i >= 1; --i) {
        for(int j = 0; j < i; ++j) {
            if(fabs(arr[j]) > fabs(arr[j + 1])) {
                // Поменять элементы местами с помощью дополнительной переменной
                float tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void printArray(float *arr, int n) {
    for(int i = 0; i < n; ++i)
        cout << arr[i] << endl;
}

int main() {
    int n;
    float *arr, sumAfterMin;
    bool flag = false;
    setlocale(LC_ALL, "russian");
    
    cout << "Введите количество элементов в массиве: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Введена некорректная длина массива" << endl;
        return 0;
    }
    
    arr = new float[n];
    for(int i = 0; i < n; ++i) {
        cout << "Введите " << i << "-й элемент: ";
        cin >> arr[i];
    }
    
    cout << "Количество элементов, равных  нулю: " << countZeroElements(arr, n) << endl;
    cout << "Сумма элементов, находящихся после минимального элемента: ";
    sumAfterMin = getSumAfterMin(arr, n, &flag);
    if (!flag) {
        cout << sumAfterMin << endl;
    } else {
        cout << "После минимального элемента ничего нет" << endl;
    }
    
    sortArray(arr, n);
    cout << "Отсортированный массив: " << endl;
    printArray(arr, n);
    
    return 0;
}
