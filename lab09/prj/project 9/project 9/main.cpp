#include <iostream>
#include <conio.h>
#include <clocale>
#include "mylib.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");

    while (true) {
        cout << "\n����:\n";
        cout << "  3 - �������� 9_3\n";
        cout << "  4 - �������� 9_2\n";
        cout << "  7 - �������� 9_1\n";
        cout << "  0 ��� 9 - ���i�\n";
        cout << "��� ����: ";

        char ch = _getch();
        cout << ch << endl;

        switch (ch) {
        case '3': task9_3(); break;
        case '4': task9_2(); break;
        case '7': task9_1(); break;
        case '0':
        case '9': cout << "���i� � ��������..." << endl; return 0;
        default:  cout << "\a���i��� ��������! ��������� �� ���." << endl; break;
        }
    }
}
