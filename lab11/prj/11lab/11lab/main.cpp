#include <iostream>
#include <locale>
#include "schedule_lib.h"
#include <windows.h>

int main() {
    // Налаштування кодування консолі для UTF-8
    //SetConsoleOutputCP(65001);
    SetConsoleCP(1251);
    setlocale(LC_CTYPE, "ukr");
    SetConsoleOutputCP(1251);
    // Налаштування локалі для коректного відображення кирилиці
 //   std::locale::global(std::locale("uk_UA.UTF-8"));
 //   std::wcout.imbue(std::locale("uk_UA.UTF-8"));
 //   std::wcin.imbue(std::locale("uk_UA.UTF-8"));

    ScheduleSystem system("schedule_data.txt");

    int choice;
    do {
        std::wcout << L"\n===== РОЗКЛАД РУХУ АВТОБУСІВ, АС Кропивницький =====\n";
        std::wcout << L"1. Пошук за станцією\n";
        std::wcout << L"2. Вивести весь розклад\n";
        std::wcout << L"3. Додати новий рейс\n";
        std::wcout << L"4. Видалити рейс за номером\n";
        std::wcout << L"5. Вийти\n";
        std::wcout << L"Ваш вибір: ";
        std::cin >> choice; // Для чисел можна залишити std::cin
        std::cin.ignore();

        switch (choice) {
        case 1: system.searchByStation(); break;
        case 2: system.printSchedule(); break;
        case 3: system.addRoute(); break;
        case 4: system.removeRoute(); break;
        case 5:
            system.saveToFile();
            std::wcout << L"Дані збережено. Завершення програми.\n";
            break;
        default:
            std::wcout << L"Невірний вибір. Спробуйте знову.\n";
        }
    } while (choice != 5);

    return 0;
}
