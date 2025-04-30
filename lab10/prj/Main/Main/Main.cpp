#include "Sarvadi_Lib.h"
#include <iostream>
#include <string>


#ifdef _WIN32
#include <windows.h>
#endif


#include <locale>
#include <codecvt>

int main() {
    
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());

    int choice;
    std::string input_file = "input.txt";
    std::string output_file = "output.txt";

    do {
        std::wcout << L"\nМеню:\n";
        std::wcout << L"1. Тицькни щоб вибрати 10.1\n";
        std::wcout << L"2. Тицькни щоб вибрати 10.2\n";
        std::wcout << L"3. Тицькни щоб вибрати 10.3\n";
        std::wcout << L"0. Тицькни\n";
        std::wcout << L"Вибери опцію: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            task_10_1(input_file, output_file);
            break;
        case 2:
            task_10_2(input_file, output_file);
            break;
        case 3:
            task_10_3(input_file, output_file);
            break;
        case 0:
            std::wcout << L"Програма завершена.\n";
            break;
        default:
            std::wcout << L"Невірний вибір. Спробуй ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}