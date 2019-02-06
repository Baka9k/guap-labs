#include <iostream>
using namespace std;

const int MAX_LENGTH = 1000;


void concatStrings(char *string1, char *string2) {
    // записывает string2 в начало string1
    
    int i, j;
    char tempString[MAX_LENGTH]; // вспомогательная строка
    // для сохранения string1
    
    // подсчитать длину string2 и сохранить ее в i
    for(i = 0; string2[i] != '\0'; ++i);
    
    // записать string1 в string1 со смещением вправо на длину string2
    for(j = 0; j < i; ++j) {
        string1[i + j] = string1[j];
    }
    string1[i + j] = '\0';
    
    // записать string2 в начало string1
    for(j = 0; j < i; ++j) {
        string1[j] = string2[j];
    }
    
}


int main() {
    
    char string1[MAX_LENGTH], string2[MAX_LENGTH];
    setlocale(LC_ALL, "russian");
    
    cout << "Введите первую строку: ";
    cin.getline(string1, MAX_LENGTH, '\n');
    // если ввели строку длиннее, чем выделено памяти, просто обрезаем
    // ее и чистим буфер
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout << "Введите вторую строку: ";
    cin.getline(string2, MAX_LENGTH, '\n');
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    concatStrings(string1, string2);
    
    cout << "Получившаяся строка: " << string1 << endl;
    
    return 0;
    
}
