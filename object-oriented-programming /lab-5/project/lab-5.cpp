// Приложение должно осуществлять ввод и вывод информации о реализованном классе.
// Заполнить массив данных (vector) случайными числами в диапазоне  m1 - m2 .
// Выполнить набор действий при помощи обобщенных алгоритмов, объектов-функций и предикатов.
// После выполнения каждого действия выводить на экран результат.
//
// Вариант 7
//
// - m1=0, m2=100
// - подсчитать количество элементов со значениями больше 10
// - найти корень квадратный из всех элементов
// - вычислить сумму всех элементов
//


#include <iostream>
#include <stdlib.h>
#include <vector>
#include <random>
#include <math.h>
using namespace std;



int const ARR_LENGTH = 10;
int const M1 = 0;
int const M2 = 100;



class MyArray {

	private:
		vector<double> content;

	public:
		void print();
		void fillWithRandomNumbers();
		int countNumberOfGT10();
		void sqrtAllElements();
		double getSumOfAllElements();

};


void MyArray::print() {
	for(int i = 0; i < content.size(); i++) {
		cout << content[i] << "   ";
	}
	cout << endl << endl;
}


void MyArray::fillWithRandomNumbers() {

	random_device rd;     // only used once to initialise (seed) engine
    mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	uniform_int_distribution<int> uni(M1, M2); // guaranteed unbiased

	for(int i = 0; i < ARR_LENGTH; i++) {
		auto random_integer = uni(rng);
		content.push_back(random_integer);
	}

}


int MyArray::countNumberOfGT10() {

	int GT10 = 0;

	for(int i = 0; i < content.size(); i++) {
		if (content[i] > 10) {
			GT10++;
		}
	}

	return GT10;

}


void MyArray::sqrtAllElements() {
	for(int i = 0; i < content.size(); i++) {
		content[i] = sqrt(content[i]);
	}
}


double MyArray::getSumOfAllElements() {

	double sum = 0;

	for(int i = 0; i < content.size(); i++) {
		sum += content[i];
	}

	return sum;

}


int main(int argc, char **argv) {
	setlocale(LC_ALL, "russian");

	MyArray arr0;

	cout << "Создаем vector и заполняем случайными числами: " << endl;
	arr0.fillWithRandomNumbers();
	arr0.print();

	cout << "Количество элементов со значением больше 10: " <<
		arr0.countNumberOfGT10() << endl << endl;

	cout << "Извлекаем корень из всех элементов: " << endl;
	arr0.sqrtAllElements();
	arr0.print();

	cout << "Сумма всех элементов: " <<
		arr0.getSumOfAllElements() << endl << endl;

	return 0;
}

