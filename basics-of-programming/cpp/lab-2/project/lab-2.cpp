#include <iostream>
using namespace std;


double checkIfPointInZone(const double x, const double y) {
    // Уравнение прямой: -x - y - 1 = 0
    return (x >= -1) && (y >= -1) && ((-x - y - 1) >= 0);
}

int main() {
    double x, y;
    bool isPointInZone;
    setlocale(LC_ALL, "russian");
    cout << "Введите значение 'x': ";
    cin >> x;
    cout << "Введите значение 'y': ";
    cin >> y;
    isPointInZone = checkIfPointInZone(x, y);
    if (isPointInZone) {
        cout << "Точка находится в заштрихованной области" << endl;
    } else {
        cout << "Точка не находится в заштрихованной области" << endl;
    }
    return 0; 
}
