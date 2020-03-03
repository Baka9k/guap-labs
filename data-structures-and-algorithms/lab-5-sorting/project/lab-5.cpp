// Использовать неупорядоченный массив A, содержащий n
// целочисленных элементов. Величина n определяется по
// согласованию с преподавателем. Дополнительно в программе
// должны быть реализованы следующие функции:
// 1) Поиск элемента либо по его порядковой позиции, либо
//     по его содержимому;
// 2) Добавление/удаление элемента с последующей пересортировкой
//     последовательности;
// 3) В программе должен быть реализован подсчет количества
//     сравнений и перестановок, при осуществлении сортировки.
//
// Вариант 26
//
// Найти k-ое по порядку число среди элементов массива
// Алгоритм сортировки - Четно – нечетная

#include <iostream>
#include <limits>
#include <time.h>
#include <stdlib.h>
using namespace std;


const int MIN_RAND_VALUE = -99;
const int MAX_RAND_VALUE = 99;


void sortArray(int *arr, int n) {
    // Четно-нечетная сортировка
    
    // Счетчики сравнений и перестановок
    int swapCounter = 0;
    int comparsionCounter = 0;
    
    for (int i = 0; i < n; i++) {
        // (i % 2) ? 0 : 1 используется для определения четности/нечетности индекса
        for (int j = (i % 2) ? 0 : 1; j < n - 1; j += 2) {
            comparsionCounter++;
            if (arr[j] > arr[j + 1]) {
                // Поменять элементы местами с помощью дополнительной переменной
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapCounter++;
            }
        }
    }
    
    cout << "Количество сравнений: " << comparsionCounter << endl;
    cout << "Количество перестановок: " << swapCounter << endl;
    
}

void fillArrWithRandomNumbers(int *arr, int n) {
    // Заполняет массив случайными числами
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = MIN_RAND_VALUE + (rand() % (MAX_RAND_VALUE - MIN_RAND_VALUE + 1));
    }
}

void addElemToArray(int *&arr, int n, int value) {
    // Добавляет элемент в массив
    // n - длина массива до добавления элемента!
    
    // Копируем массив в новый массив длины n+1
    int *newArr = new int[n + 1];
    for (int i = 0; i < n; i++) {
        newArr[i] = arr[i];
    }
    // Удаляем старый массив
    delete[] arr;
    // В последний элемент нового массива записываем value
    newArr[n] = value;
    // Записываем в arr ссылку на новый массив
    arr = newArr;
}

void deleteElemFromArray(int *&arr, int n, int index) {
    // Удаляет элемент из массива
    // n - длина массива до удаления элемента!
    
    // Копируем массив в новый массив длины n-1 до index
    int *newArr = new int[n - 1];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    // Копируем остальные элементы, пропустив index
    for (int i = (index + 1); i < n; i++) {
        newArr[i - 1] = arr[i];
    }
    // Удаляем старый массив
    delete[] arr;
    // Записываем в arr ссылку на новый массив
    arr = newArr;
}

int findElemByValue(int *arr, int n, int value) {
    // Возвращает индекс элемента, если он найден, и -1 если не найден
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void printArray(int *arr, int n) {
    cout << "=========== МАССИВ ==========" << endl;
    for(int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) {
            cout << "\t ";
        }
    }
    cout << endl << "=============================" << endl;
    
}

int main() {
    
    setlocale(LC_ALL, "russian");
    
    int n; // Длина массива
    int *arr; // Указатель на массив
    
    // Ввод длины массива
    cout << "Введите количество элементов в массиве: ";
    cin >> n;
    while (cin.fail() || n <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введена некорректная длина массива!" << endl;
        cout << "Повторите ввод: ";
        cin >> n;
    }
    
    arr = new int[n];
    fillArrWithRandomNumbers(arr, n);
    cout << "Массив создан и заполнен случайными числами от "
        << MIN_RAND_VALUE << " до " << MAX_RAND_VALUE << endl;
    
    // Меню пользователя
    int menuInput = -1;
    int userInput = -1;
    
    while (menuInput != 0) {
        cout << endl <<
        "====== ДОСТУПНЫЕ КОМАНДЫ =====" << endl <<
        "1 - Вывести массив на экран" << endl <<
        "2 - Отсортировать массив" << endl <<
        "3 - Поиск элемента по индексу" << endl <<
        "4 - Поиск элемента по значению" << endl <<
        "5 - Добавить элемент в массив и отсортировать заново" << endl <<
        "6 - Удалить элемент из массива по индексу и "
            << "отсортировать заново" << endl <<
        "7 - Удалить элемент из массива по значению и "
            << "отсортировать заново" << endl <<
        "0 - Выход" << endl <<
        "==============================" << endl <<
        "Выберите действие: ";
        cin >> menuInput;
        cout << endl;
        while (cin.fail() || (menuInput < 0) || (menuInput > 7)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода, выберите действие: ";
            cin >> menuInput;
        }
        switch (menuInput) {
                
            // Вывести массив на экран
            case 1: {
                printArray(arr, n);
                break;
                
            // Отсортировать массив
            } case 2: {
                sortArray(arr, n);
                cout << "Массив отсортирован!" << endl;
                break;
                
            // Поиск элемента по индексу
            } case 3: {
                cout << "Введите индекс: ";
                cin >> userInput;
                while (cin.fail() || userInput < 0 || userInput >= n) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Индекс должен быть меньше длины массива!"
                        << endl << "Повторите ввод: ";
                    cin >> userInput;
                }
                cout << "Элемент с индексом " << userInput << " имеет значение "
                    << arr[userInput] << endl;
                break;
                
            // Поиск элемента по значению
            } case 4: {
                cout << "Введите значение: ";
                cin >> userInput;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Вы должны ввести целое число!"
                    << endl << "Повторите ввод: ";
                    cin >> userInput;
                }
                int foundIndex = findElemByValue(arr, n, userInput);
                if (foundIndex == -1) {
                    cout << "Элемент с данным значением не найден" << endl;
                } else {
                    cout << "Элемент со значением " << userInput <<
                    " найден по индексу " << foundIndex << endl;
                }
                break;
                
            // Добавить элемент в массив и отсортировать заново
            } case 5: {
                cout << "Введите новый элемент массива: ";
                cin >> userInput;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Вы ввели недопустимое значение, попробуйте еще: ";
                    cin >> userInput;
                }
                addElemToArray(arr, n, userInput);
                n++;
                cout << "Элемент добавлен!" << endl;
                sortArray(arr, n);
                cout << "Массив отсортирован!" << endl;
                break;
                
            // Удалить элемент из массива по индексу и
            //    отсортировать заново
            } case 6: {
                cout << "Введите индекс элемента, который хотите удалить: ";
                cin >> userInput;
                while (cin.fail() || userInput < 0 || userInput >= n) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Индекс должен быть меньше длины массива!"
                    << endl << "Повторите ввод: ";
                    cin >> userInput;
                }
                deleteElemFromArray(arr, n, userInput);
                n--;
                cout << "Элемент удален!" << endl;
                sortArray(arr, n);
                cout << "Массив отсортирован!" << endl;
                break;
                
            // Удалить элемент из массива по значению и
            //    отсортировать заново
            } case 7: {
                cout << "Введите значение элемента, который хотите удалить: ";
                cin >> userInput;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Вы ввели недопустимое значение, попробуйте еще: ";
                    cin >> userInput;
                }
                int foundIndex = findElemByValue(arr, n, userInput);
                if (foundIndex == -1) {
                    cout << "Элемент с данным значением не найден" << endl;
                } else {
                    deleteElemFromArray(arr, n, foundIndex);
                    n--;
                    cout << "Элемент со значением " << userInput <<
                    " найден по индексу " << foundIndex << " и удален." << endl;
                    sortArray(arr, n);
                    cout << "Массив отсортирован!" << endl;
                }
                break;
            }
        }
    }
    
    return 0;
}
