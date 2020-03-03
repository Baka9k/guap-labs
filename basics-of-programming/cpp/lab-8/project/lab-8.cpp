#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void replaceDigitsWithWordsAndAddNewlines() {
    
    // Открыть первый файл
    ifstream file1("file1.txt");
    if (!file1) {
        cout << "Не удалось открыть файл file1.txt" << endl;
        return;
    }
    
    // Определить длину файла, создать буфер нужного размера
    file1.seekg(0, ios::end);
    const long fileLength = file1.tellg();
    char *inputBuffer = new char [fileLength + 1];
    
    // Записать файл в буфер
    file1.seekg(0, ios::beg);
    file1.read(inputBuffer, fileLength);
    inputBuffer[fileLength] = '\0';
    
    file1.close();
    
    // Создать второй буфер
    // В худшем случае длина текста после обработки будет
    const long outputBufferLength = (fileLength * 6) + (fileLength * 2) + 1;
    // Если все цифры будут заменены на слово из 6 букв ("девять")
    // и каждый символ будет отдельным предложением
    char *outputBuffer = new char [outputBufferLength];
    outputBuffer[outputBufferLength] = '\0';
    
    long i = 0;
    string replacementText;
    // Поскольку один символ заменаяется несколькими, позиция чтения
    // из первого буфера и позиция записи во второй буфер различаются
    long offset; // Смещение позиции записи во второй буфер
    
    while (inputBuffer[i]) {
        
        switch(inputBuffer[i]) {
            case '0': replacementText = "ноль"; break;
            case '1': replacementText = "один"; break;
            case '2': replacementText = "два"; break;
            case '3': replacementText = "три"; break;
            case '4': replacementText = "четыре"; break;
            case '5': replacementText = "пять"; break;
            case '6': replacementText = "шесть"; break;
            case '7': replacementText = "семь"; break;
            case '8': replacementText = "восемь"; break;
            case '9': replacementText = "девять"; break;
            case '?': replacementText = "?\n"; break;
            case '!': replacementText = "!\n"; break;
            case '.': replacementText = ".\n"; break;
            default: replacementText = "";
        }
        
        if (replacementText == "") {
            outputBuffer[i + offset] = inputBuffer[i];
        } else {
            for (int j = 0; j < replacementText.length(); j++) {
                outputBuffer[i + offset] = replacementText.at(j);
                offset++;
            }
        }
    
        i++;
    }
    
    // Открыть второй файл
    ofstream file2("file2.txt");
    if (!file2) {
        cout << "Не удалось открыть файл file2.txt" << endl;
        return;
    }
    
    // Записать второй буфер в файл
    file2.write(outputBuffer, outputBufferLength);
    file2.close();
    
    // Удалить буферы
    delete[] inputBuffer;
    delete[] outputBuffer;
    
}

int main() {
    setlocale(LC_ALL, "russian");
    replaceDigitsWithWordsAndAddNewlines();
    return 0;
}

