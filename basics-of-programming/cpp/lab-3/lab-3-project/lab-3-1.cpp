#include <iostream>
using namespace std;


short pack(short t, short s, short l) {
    return l | s << 8 | t << 13;
}

short getCorrectInput(char varName, const short limit) {
    int userInput;
    cout << "Введите " << varName << ": ";
    cin >> userInput;
    
    while (cin.fail()
        || userInput > limit
        || userInput < 0
    ) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Вы должны ввести число от 0 до " << limit << "!" << endl;
        cout << "Введите " << varName << ": ";
        cin >> userInput;
    }
    
    return userInput;
}

int main() {
    setlocale(LC_ALL, "russian");
    int t = getCorrectInput('t', 7);
    int s = getCorrectInput('s', 15);
    int l = getCorrectInput('l', 255);
    cout << "Упакованная структура в 16-ричной системе: " << hex << pack(t, s, l) << endl;
    return 0;
}
