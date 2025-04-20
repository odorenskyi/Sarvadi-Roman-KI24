#include <iostream>
#include <iomanip>
#include <bitset>
#include <clocale>
#include "mylib.h"
using namespace std;

void task9_1() {
    setlocale(LC_ALL, "");
    int bal;
    cout << "Введіть бал Бофорта (0-12): ";
    cin >> bal;

    if (bal < 0 || bal > 12) {
        cout << "Неправильне значення бала!" << endl;
        return;
    }

    double minSpeed[] = { 0.0, 0.3, 1.6, 3.4, 5.5, 8.0, 10.8, 13.9, 17.2, 20.8, 24.5, 28.5, 32.7 };
    double maxSpeed[] = { 0.3, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8, 17.1, 20.7, 24.4, 28.4, 32.6, 999 };

    double minKmh = minSpeed[bal] * 3.6;
    double maxKmh = maxSpeed[bal] * 3.6;

    cout << fixed << setprecision(1);
    cout << "Сила вітру при " << bal << " бал(ах): від "
        << minKmh << " км/год до " << maxKmh << " км/год" << endl;
}

void task9_2() {
    setlocale(LC_ALL, "");
    double ukrSizes[] = { 35, 36, 36.5, 37, 38, 38.5, 39, 40, 41, 41.5, 42, 42.5, 43, 44, 45, 46, 47, 47.5, 48, 48.5 };
    double sizesCm[] = { 23, 23.5, 24, 24.5, 25, 25.5, 26, 26.5, 27, 27.5, 28, 28.5, 29, 30, 30.5, 31, 31.5, 32, 32.5, 33 };

    double input;
    cout << "Введiть розмiр взуття в системi України: ";
    cin >> input;

    bool found = false;
    for (int i = 0; i < size(ukrSizes); ++i) {
        if (input == ukrSizes[i]) {
            cout << fixed << setprecision(1);
            cout << "Вiдповiдний розмiр у сантиметрах: " << sizesCm[i] << " см" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Немає такого розмiру в таблицi!" << endl;
    }
}

void task9_3() {
    setlocale(LC_ALL, "");
    int N;
    cout << "Введiть число N (від 1000 до 10000): ";
    cin >> N;

    if (N < 1000 || N > 10000) {
        cout << "Число не в дiапазонi!" << endl;
        return;
    }

    bitset<16> bin(N);
    bool D15 = bin[15];
    int result = D15 ? bin.count() : 16 - bin.count();

    cout << "Результат: " << result << endl;
}

