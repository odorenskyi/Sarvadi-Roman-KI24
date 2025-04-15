#include <iostream>
#include "ModulesSarvadi.h"
#include <windows.h>
#include <iomanip>
using namespace std;
void test_s_calculation() {

    double x[10] = { 1.0,  0.5,  0.25,  1.5,  2.0,
                     1.25, 3.0,  3.05,  4.5,  5.0 };
    double y[10] = { 2.0,  1.5,  0.5,   1.0,  2.5,
                     3.5,  0.75, 2.2,   4.0,  1.1 };
    double z[10] = { 3.0,  2.5,  1.5,   4.0,  5.0,
                     2.75, 4.5,  3.85,  6.0,  2.2 };
    double expected[10] = { 0.85663825121084791, 1.7670500990669220, 0.47890767596761230, 0.98139074149390915, 11.588866325158358 ,
                           3.8626375773104531 , 3.8722986600764733, 24.207131856780300, 1272.2250741448154,7.4472828351119595 };
    cout << "Запуск тестів для функції calculateS:\n";
    for (int i = 0; i < 10; i++) {
        double result = calculateS(x[i], y[i], z[i]);
        cout << "Тест кейс #" << (i + 1)
            << " | x = " << x[i]
            << ", y = " << y[i]
            << ", z = " << z[i]
            << " | Результат = " << result
            << " | Очікуваний результат = " << expected[i];
        if (result == expected[i]) {
            cout << " -> PASSED\n";
        }
        else {
            cout << " -> FAILED\n";
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    test_s_calculation();
    system("pause");
    return 0;
}