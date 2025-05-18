#include "schedule_lib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include <windows.h>

ScheduleSystem::ScheduleSystem(const std::string& file) : filename(file) {
    loadFromFile();
}

void ScheduleSystem::loadFromFile() {
    std::cout << "Спроба відкрити файл: " << filename << "\n";
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Не вдалося відкрити файл: " << filename << "\n";
        return;
    }

    routes.clear();
    std::string line;
    int lineNumber = 0;
    while (std::getline(fin, line)) {
        std::cout << line << std::endl;
        lineNumber++;
        if (line.empty()) continue; // Пропустити порожні рядки

        std::stringstream ss(line);
        std::string field;
        BusRoute r;

        try {
            // Зчитуємо поля
            if (!std::getline(ss, field, ';') || field.empty()) throw std::runtime_error("Неправильний ID");
            r.id = std::stoi(field);
            if (!std::getline(ss, r.route, ';') || r.route.empty()) throw std::runtime_error("Неправильний маршрут");
            if (!std::getline(ss, r.frequency, ';') || r.frequency.empty()) throw std::runtime_error("Неправильна періодичність");
            if (!std::getline(ss, r.period, ';') || r.period.empty()) throw std::runtime_error("Неправильний період");
            if (!std::getline(ss, r.startArrive, ';') || r.startArrive.empty()) throw std::runtime_error("Неправильне прибуття (початкова)");
            if (!std::getline(ss, r.startDepart, ';') || r.startDepart.empty()) throw std::runtime_error("Неправильне відправлення (початкова)");
            if (!std::getline(ss, r.endDepart, ';') || r.endDepart.empty()) throw std::runtime_error("Неправильне відправлення (кінцева)");
            if (!std::getline(ss, r.endArrive, ';') || r.endArrive.empty()) throw std::runtime_error("Неправильне прибуття (кінцева)");

            routes.push_back(r);
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка в рядку " << lineNumber << ": " << e.what() << "\n";
        }
    }
    fin.close();
    std::cout << "Зчитано " << routes.size() << " рейсів.\n";
}

void ScheduleSystem::saveToFile() const {
    std::ofstream fout(filename);
    if (!fout) {
        std::cerr << "Не вдалося зберегти файл: " << filename << "\n";
        return;
    }
    for (const auto& r : routes) {
        fout << r.id << ";" << r.route << ";" << r.frequency << ";" << r.period << ";"
            << r.startArrive << ";" << r.startDepart << ";" << r.endDepart << ";" << r.endArrive << "\n";
    }
    fout.close();
    std::cout << "Дані збережено у файл: " << filename << "\n";
}

void ScheduleSystem::printSchedule() const {
    std::cout << "Кількість рейсів: " << routes.size() << "\n";
    if (routes.empty()) {
        std::cout << "Розклад порожній або не завантажено.\n";
        return;
    }

    for (const auto& r : routes) {
        std::cout << "ID: " << r.id << "\n"
            << "Маршрут: " << r.route << "\n"
            << "Періодичність: " << r.frequency << "\n"
            << "Період дії: " << r.period << "\n"
            << "Прибуття (початкова): " << r.startArrive << "\n"
            << "Відправлення (початкова): " << r.startDepart << "\n"
            << "Відправлення (кінцева): " << r.endDepart << "\n"
            << "Прибуття (кінцева): " << r.endArrive << "\n"
            << "------------------------------------\n";
    }
}

void ScheduleSystem::searchByStation() const {
    std::string name;
    std::cout << "Введіть назву станції (початкову або кінцеву): ";
    std::getline(std::cin, name);

    std::string lowered;
    std::transform(name.begin(), name.end(), std::back_inserter(lowered), ::tolower);

    bool found = false;
    for (const auto& r : routes) {
        std::string route_lower = r.route;
        std::transform(route_lower.begin(), route_lower.end(), route_lower.begin(), ::tolower);
        if (route_lower.find(lowered) != std::string::npos) {
            std::cout << "ID: " << r.id << " — " << r.route << " (" << r.frequency << ", " << r.period << ")\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "Рейсів за вказаною станцією не знайдено.\n";
    }
}

void ScheduleSystem::addRoute() {
    BusRoute r;
    std::cout << "Номер рейсу (ID): ";
    std::cin >> r.id;
    std::cin.ignore();

    // Перевірка унікальності ID
    for (const auto& route : routes) {
        if (route.id == r.id) {
            std::cout << "Рейс з таким ID уже існує!\n";
            return;
        }
    }

    std::cout << "Маршрут: "; std::getline(std::cin, r.route);
    std::cout << "Періодичність: "; std::getline(std::cin, r.frequency);
    std::cout << "Період дії: "; std::getline(std::cin, r.period);
    std::cout << "Прибуття (початкова): "; std::getline(std::cin, r.startArrive);
    std::cout << "Відправлення (початкова): "; std::getline(std::cin, r.startDepart);
    std::cout << "Відправлення (кінцева): "; std::getline(std::cin, r.endDepart);
    std::cout << "Прибуття (кінцева): "; std::getline(std::cin, r.endArrive);

    routes.push_back(r);
    std::cout << "Рейс додано.\n";
}

void ScheduleSystem::removeRoute() {
    int id;
    std::cout << "Введіть номер рейсу для видалення: ";
    std::cin >> id;
    std::cin.ignore();

    auto it = std::remove_if(routes.begin(), routes.end(), [id](const BusRoute& r) {
        return r.id == id;
        });

    if (it != routes.end()) {
        routes.erase(it, routes.end());
        std::cout << "Рейс видалено.\n";
    }
    else {
        std::cout << "Рейс не знайдено.\n";
    }
}