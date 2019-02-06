#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;


const int MATRIX_SIZE = 5; // Размерность матрицы


void fillMatrixWithRandomNumbers(int matrix[][MATRIX_SIZE], int min, int max) {
    
    // initialize random seed
    srand(time(NULL));
    
    // заполняет матрицу случайными числами от min до max
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = min + (rand() % (max - min + 1));
        }
    }
    
}

void printMatrix(int matrix[][MATRIX_SIZE]) {
    // печатает матрицу
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            cout << matrix[i][j];
            if (i < MATRIX_SIZE && j < MATRIX_SIZE - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

void shiftMatrix(int matrix[][MATRIX_SIZE], int nShifts) {
    
    int i, j, c, edge;
    int layerBeforeShift[4 * (MATRIX_SIZE - 1)];
    int layerAfterShift[4 * (MATRIX_SIZE - 1)];
    
    // Для каждого слоя матрицы,
    for(int k = 0; k < MATRIX_SIZE / 2; k++) {
        edge = MATRIX_SIZE - 1 - k;
        
        // записать слой в layerBeforeShift
        c = 0;
        for(j = k; j < edge; j++) {
            layerBeforeShift[c] = matrix[k][j];
            c++;
        }
        for(i = k; i < edge; i++) {
            layerBeforeShift[c] = matrix[i][edge];
            c++;
        }
        for(j = edge; j >= k; j--) {
            layerBeforeShift[c] = matrix[edge][j];
            c++;
        }
        for(i = edge - 1; i > k; i--) {
            layerBeforeShift[c] = matrix[i][k];
            c++;
        }
        
        // переставить элементы и записать их в layerAfterShift
        for(i = 0; i < (4 * (MATRIX_SIZE - 2 * k - 1)); i++)
            layerAfterShift[(i + nShifts) % (4 * (MATRIX_SIZE - 2 * k - 1))] = layerBeforeShift[i];
        
        // записать layerAfterShift обратно в матрицу
        c = 0;
        for(j = k; j < edge; j++) {
            matrix[k][j] = layerAfterShift[c];
            c++;
        }
        for(i = k; i < edge; i++) {
            matrix[i][edge]= layerAfterShift[c];
            c++;
        }
        for(j = edge; j >= k; j--) {
            matrix[edge][j]= layerAfterShift[c];
            c++;
        }
        for(i = edge - 1; i > k; i--) {
            matrix[i][k]= layerAfterShift[c];
            c++;
        }
    }
    
}

int main() {
    
    setlocale(LC_ALL, "russian");
    int matrix[MATRIX_SIZE][MATRIX_SIZE], nShifts;
    
    fillMatrixWithRandomNumbers(matrix, 10, 99);
    cout << "Исходная матрица:" << endl;
    printMatrix(matrix);
    
    cout << "Введите количество элементов, на которое " << endl;
    cout << "будет проведен циклический сдвиг матрицы: ";
    cin >> nShifts;
    
    shiftMatrix(matrix, nShifts);
    
    cout << endl << "Матрица, сдвинутая на ";
    cout << nShifts << " элементов:" << endl;
    printMatrix(matrix);
    
    return 0;
}
