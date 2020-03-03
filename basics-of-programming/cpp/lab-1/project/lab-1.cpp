#include <iostream>
#include <math.h>
using namespace std;

const double PI =3.141592653589793238462;
double degToRad(const double angleInDegrees);
double sec(const double angle);
double calcZ1(const double a);
double calcZ2(const double a);

int main() {
    double a, aInRadians;
    setlocale(LC_ALL, "russian");
    cout << "Введите значение 'a' в градусах: ";
    cin >> a;
    aInRadians = degToRad(a);
    cout << "z1 = " << calcZ1(aInRadians) << endl;
    cout << "z2 = " << calcZ2(aInRadians) << endl;
    if (calcZ1(aInRadians) == calcZ2(aInRadians)) {
        cout << "z1 == z2" << endl;
    }
    return 0;
}


double degToRad(const double angleInDegrees) {
    return angleInDegrees * PI / 180;
}

double sec(const double angle) {
  return 1 / cos(angle);
}

double calcZ1(const double a) {
    return (cos(a) + sin(a)) / (cos(a) - sin(a));
}

double calcZ2(const double a) {
    return tan(2 * a) + sec(2 * a);
}

