#include <iostream>
using namespace std;


void unpackAndPrint(int packedHex) {
    cout << "Значение T в данной структуре десятичном виде: ";
    cout << dec << ((packedHex >> 13) & 0x7) << endl;
    cout << "Значение S в данной структуре десятичном виде: ";
    cout << dec << ((packedHex >> 8) & 0xF) << endl;
    cout << "Значение L в данной структуре десятичном виде: ";
    cout << dec << (packedHex & 0xFF) << endl;
}

int main() {
    int packedHex;
    setlocale(LC_ALL, "russian");
    cout << "Введите упакованную структуру в 16-ричной системе: ";
    cin >> hex >> packedHex;
    
    if (
        cin.fail() ||                  // Неверный тип
        ((packedHex >> 12) & 1) != 0   // 12-й бит не 0
        ) {
        cout << "Некорректно введена структура" << endl;
        return 0;
    }
    
    unpackAndPrint(packedHex);
    return 0;
}
