#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h> 


using namespace std;

void addSong() {
    string sTitle, sLyrics, filename;
    cout << "Введите название песни: ";
    getline(cin, sTitle);
    filename = sTitle;
    replace(filename.begin(), filename.end(), ' ', '_');
    filename += ".txt";
    cout << "Введите текст этой песни (завершите ввод пустой строкой):" << endl;
    while (true) {
        string line;
        getline(cin, line);
        if (line.empty()) {
            break;
        }
        sLyrics += line + "\n";
    }
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << sLyrics;
        outFile.close();
        cout << "Песня сохранена в " << filename << endl;
    }
    else {
        cout << "Невозможно открыть файл для записи." << endl;
    }
}



void viewSong() {
    string sTitle, filename;
    cout << "Введите название песни для просмотра: ";
    cin.ignore();
    getline(cin, sTitle);
    filename = sTitle;
    replace(filename.begin(), filename.end(), ' ', '_');
    filename += ".txt";
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        cout << "Содержимое " << filename << ":" << endl;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cout << "Невозможно открыть файл " << filename << endl;
    }
}



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Добавить песню" << endl;
        cout << "2. Посмотреть песню" << endl;
        cout << "3. Выйти" << endl;
        cout << "Что вы выбираете (1-3): ";
        cin >> choice;
        switch (choice) {
        case '1':
            cin.ignore();
            addSong();
            break;
        case '2':
            viewSong();
            break;
        case '3':
            cout << "Выход..." << endl;
            break;
        default:
            cout << "Неправильный ввод, введите 1, 2 или 3." << endl;
        }
    } while (choice != '3');
    return 0;
}