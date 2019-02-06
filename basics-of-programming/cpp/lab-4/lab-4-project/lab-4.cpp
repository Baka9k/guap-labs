#include <iostream>
#include <cmath>
#include <string>
using namespace std;


double calcF(
                const double a,
                const double b,
                const double c,
                const double x,
                bool *flag
             ) {
    
    if (((x + c) < 0) && (a != 0)) {
        *flag = false;
        return (-1 * pow(a, 3) * x) - b;
    }
    
    if (((x + c) > 0) && (a == 0)) {
        if ((x - c) == 0) {
            // cout << "Невозможно вычислить: деление на ";
            *flag = true;
            return 0;
        }
        *flag = false;
        return (x - a) / (x - c);
    }
    
    if (x == 0 || c == 0) {
        // cout << "Невозможно вычислить: деление на ";
        *flag = true;
        return 0;
    }
    *flag = false;
    return (x / c) + (c / x);
}

double input(const string varName) {
    double userInput;
    cout << "Введите значение " << varName << ": ";
    cin >> userInput;
    return userInput;
}

int main() {
    
    setlocale(LC_ALL, "russian");
    double a, b, c, x1, x2, dx;
    bool flag = false;
    double result;
    
    a = input("a");
    b = input("b");
    c = input("c");
    x1 = input("x1");
    x2 = input("x2");
    dx = input("dx");
    
    if ( // Цикл будет бесконечным при выполнении этих условий:
        ((x1 < x2) && (dx <= 0))
        || ((x1 > x2) && (dx >= 0))
        || (dx == 0)
        ) {
        cout << "Введены некорректные данные, проверьте x1, x2 и dx" << endl;
        return 0;
    }
    
    for (double x = x1; x <= x2; x += dx) {
        cout << "F(" << x << ") = ";
        result = calcF(a, b, c, x, &flag);
        if (flag) {
            cout << "Невозможно вычислить: деление на 0" << endl;
        } else {
            cout << result << endl;
        }

    }
    
    return 0;
}
