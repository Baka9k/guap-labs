// В работе необходимо реализовать класс в соответствии с вариантом задания и создать приложение.
// Поля класса должны иметь спецификатор доступа private.
// Доступ к полям осуществляется через public методы. В функции main() создается объект на основе
//	созданного класса и осуществляется вызов методов класса.
//
// Вариант 7
//
// Целочисленные поля x и y представляют собой координаты клетки шахматной доски.
// Учитывая, что левое нижнее поле доски (1, 1) является черным, реализовать
//   метод, проверяющий истинность высказывания: «Данное поле является белым».


#include <iostream>
#include <stdlib.h>
using namespace std;


// определение класса
class ChessBoardCell {

	private:
		int x;
		int y;

	public:
		int setX(int x);
		int setY(int y);
		void printCell();
		bool checkIsCellWhite();

};

// определение методов
int ChessBoardCell::setX(int inputX) {
	if ( (inputX < 1) || (inputX > 8) ) {
		cout << "Недопустимое значение X\n";
		return 1;
	}
	x = inputX;
	return 0;
}

int ChessBoardCell::setY(int inputY) {
	if ( (inputY < 1) || (inputY > 8) ) {
		cout << "Недопустимое значение Y\n";
		return 1;
	}
	y = inputY;
	return 0;
}

void ChessBoardCell::printCell() {
	cout << "X: " << x << "\n";
	cout << "Y: " << y << "\n";
}

bool ChessBoardCell::checkIsCellWhite() {
	return (x % 2) != (y % 2);
}


int main(int argc, char **argv) {
	setlocale(LC_ALL, "russian");

	ChessBoardCell cell;

	int code = 1;
	int input = 0;

	while (code != 0) {
		cout << "Введите значение X: ";
		cin >> input;
		code = cell.setX(input);
	}

	code = 1;
	while (code != 0) {
		cout << "Введите значение Y: ";
		cin >> input;
		code = cell.setY(input);
	}

	cout << "Создан объект со свойствами:\n";
	cell.printCell();

	cout << "Результат выполнения проверки, является ли клетка белой:\n";
	cout << (cell.checkIsCellWhite() ? "да" : "нет") << endl << endl;

	return 0;
}
