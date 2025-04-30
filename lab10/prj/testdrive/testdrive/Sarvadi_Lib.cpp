#include "Sarvadi_Lib.h"
#include <fstream>
#include <iostream>
#include <bitset>
#include <ctime>


void create_input_file(const std::string& input_file, int task_number) {
    std::ifstream check(input_file);
    if (!check.is_open()) {
        std::ofstream create(input_file);
        if (create.is_open()) {
            if (task_number == 1) {
                create << "Це приклад тексту для задачі 10.1. Друге речення.";
            }
            else if (task_number == 2) {
                create << "Це приклад із літерами ї, є, і для транслітерації.";
            }
            else if (task_number == 3) {
                create << "10 20 30 40"; 
            }
            create.close();
            std::cout << "Файл " << input_file << " створено з базовим вмістом для задачі " << task_number << ".\n";
        }
    }
    check.close();
}


void create_output_file(const std::string& output_file) {
    std::ifstream check(output_file);
    if (!check.is_open()) {
        std::ofstream create(output_file);
        if (create.is_open()) {
            create.close();
            std::cout << "Файл " << output_file << " створено.\n";
        }
    }
    check.close();
}


void task_10_1(const std::string& input_file, const std::string& output_file) {
    create_input_file(input_file, 1);
    create_output_file(output_file);

    std::ifstream in(input_file);
    std::ofstream out(output_file);
    if (!in.is_open() || !out.is_open()) {
        std::cerr << "Помилка відкриття файлів у задачі 10.1\n";
        return;
    }

    std::string author = "Ім'я та прізвище розробника модуля, місто, країна, рік розробки";
    std::string sentence;
    size_t char_count = 0; 

    std::getline(in, sentence, '.');
    char_count = sentence.length();

    out << "Авторська інформація: " << author << "\n";
    out << "Кількість знаків: " << char_count << "\n";
    out << "Речення: " << sentence << ".\n";

    in.close();
    out.close();
    std::cout << "Задача 10.1 виконана. Результати у файлі: " << output_file << "\n";
}


void task_10_2(const std::string& input_file, const std::string& output_file) {
    create_input_file(input_file, 2);
    create_output_file(output_file);

    std::ifstream in(input_file);
    std::ofstream out(output_file);
    if (!in.is_open() || !out.is_open()) {
        std::cerr << "Помилка відкриття файлів у задачі 10.2\n";
        return;
    }

    std::string text;
    std::getline(in, text, '\0');

    
    std::string transliterated_text;
    for (const char& c : text) {
        if (c == 'і') transliterated_text += "i";
        else if (c == 'ї') transliterated_text += "yi";
        else if (c == 'є') transliterated_text += "ye";
        else transliterated_text += c;
    }

    out << "Транслітерований текст із вхідного файлу\n";
    out << "Джерело: Постанова Кабінету Міністрів України від 27 січня 2010 року №55\n";
    out << "Формат дати: ДД/ММ/РР\n";
    out << "Текст: " << transliterated_text << "\n";

    in.close();
    out.close();
    std::cout << "Задача 10.2 виконана. Результати у файлі: " << output_file << "\n";
}


void task_10_3(const std::string& input_file, const std::string& output_file) {
    create_input_file(input_file, 3);
    create_output_file(output_file);

    std::ifstream in(input_file);
    std::ofstream out(output_file);
    if (!in.is_open() || !out.is_open()) {
        std::cerr << "Помилка відкриття файлів у задачі 10.3\n";
        return;
    }

    int x, y, z, b;
    in >> x >> y >> z >> b;

    int s = x + y + z;

    out << "x у двійковому коді: " << std::bitset<8>(x) << "\n";
    out << "y у двійковому коді: " << std::bitset<8>(y) << "\n";
    out << "z у двійковому коді: " << std::bitset<8>(z) << "\n";
    out << "b у двійковому коді: " << std::bitset<8>(b) << "\n";
    out << "Сума x+y+z у двійковому коді: " << std::bitset<16>(s) << "\n";

    
    std::time_t now = std::time(nullptr);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now);
    out << "Час виконання: " << buffer;

    in.close();
    out.close();
    std::cout << "Задача 10.3 виконана. Результати у файлі: " << output_file << "\n";
}