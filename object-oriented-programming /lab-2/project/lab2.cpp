// В работе необходимо реализовать класс. В классе должен быть предусмотрен 
//   конструктор для установки начальных значений полей, конструктор по умолчанию, 
//   конструктор копирования, деструктор. 
//
// Поля класса должны иметь спецификатор доступа private. 
// Доступ к полям осуществляется через public методы.
//
// Поля могут быть объявлены,  как  указатели.  
// При  использовании указателей  в конструкторе класса должна быть инициализация полей, 
//   через оператор new, в деструкторе освобождение памяти, через оператор delete.
//
// В функции main() создается не менее 3 объектов класса (с использованием всех конструкторов)
//   и осуществляется вызов методов класса.
//
//
// Вариант 17
//
// Определите класс CYL, который имеет конструктор с двумя параметрами (высота и радиус).
// Создать функцию-член, вычисляющую объем цилиндра. 
// Если в конструктор не передаются параметры, то вычислить объем со стороной 5.


#include <iostream>
#include <stdlib.h>
using namespace std;


class CYL {

	private:
		float height;
		float radius;

	public:
		// Конструктор по умолчанию
		CYL();
		// Конструктор с параметрами
		CYL(float h, float r);
		// Конструктор копирования
		CYL(const CYL& other);
		// Деструктор
		~CYL();
		void print();
		float getVolume();

};


CYL::CYL() {
	height = 5;
	radius = 5;
}


CYL::CYL(float h, float r) {
	height = h;
	radius = r;
}


CYL::CYL(const CYL& other) {
	this->height = other.height;
	this->radius = other.radius;
}


CYL::~CYL() {
	// Среди атрибутов класса только примитивы, поэтому ничего не 
	//   нужно удалять в деструкторе вручную
	cout << "Объект удален" << endl;
}


void CYL::print() {
	cout << "height: " << height << endl << "radius: " << radius << endl << endl;
}


float CYL::getVolume() {
	return 3.14 * radius * radius * height;
}


int main(int argc, char **argv) {
	setlocale(LC_ALL, "russian");

	// Создаем объект с помощью конструктора по умолчанию
	CYL cylinder1;
	cylinder1.print();
	// Создаем копию объекта (при этом используется созданный ранее конструктор копирования)
	CYL cylinder1_clone = cylinder1;
	cylinder1_clone.print();

	// Создаем объект с помощью конструктора с параметрами
	CYL cylinder2(10, 5);
	cylinder2.print();
	cout << "Объем цилиндра: " << cylinder2.getVolume() << endl << endl;

	cout << "Объем цилиндра, созданного конструктором по умолчанию: " << cylinder1.getVolume() << endl << endl;

	// Перед выходом из блока main для объектов будет вызван их деструктор
}