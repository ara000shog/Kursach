#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h> 


using namespace std;

void addSong() {
    string sTitle, sLyrics, filename;
    cout << "������� �������� �����: ";
    getline(cin, sTitle);
    filename = sTitle;
    replace(filename.begin(), filename.end(), ' ', '_');
    filename += ".txt";
    cout << "������� ����� ���� ����� (��������� ���� ������ �������):" << endl;
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
        cout << "����� ��������� � " << filename << endl;
    }
    else {
        cout << "���������� ������� ���� ��� ������." << endl;
    }
}



void viewSong() {
    string sTitle, filename;
    cout << "������� �������� ����� ��� ���������: ";
    cin.ignore();
    getline(cin, sTitle);
    filename = sTitle;
    replace(filename.begin(), filename.end(), ' ', '_');
    filename += ".txt";
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        cout << "���������� " << filename << ":" << endl;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cout << "���������� ������� ���� " << filename << endl;
    }
}



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char choice;
    do {
        cout << "����:" << endl;
        cout << "1. �������� �����" << endl;
        cout << "2. ���������� �����" << endl;
        cout << "3. �����" << endl;
        cout << "��� �� ��������� (1-3): ";
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
            cout << "�����..." << endl;
            break;
        default:
            cout << "������������ ����, ������� 1, 2 ��� 3." << endl;
        }
    } while (choice != '3');
    return 0;
}