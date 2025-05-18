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
    std::cout << "������ ������� ����: " << filename << "\n";
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "�� ������� ������� ����: " << filename << "\n";
        return;
    }

    routes.clear();
    std::string line;
    int lineNumber = 0;
    while (std::getline(fin, line)) {
        std::cout << line << std::endl;
        lineNumber++;
        if (line.empty()) continue; // ���������� ������ �����

        std::stringstream ss(line);
        std::string field;
        BusRoute r;

        try {
            // ������� ����
            if (!std::getline(ss, field, ';') || field.empty()) throw std::runtime_error("������������ ID");
            r.id = std::stoi(field);
            if (!std::getline(ss, r.route, ';') || r.route.empty()) throw std::runtime_error("������������ �������");
            if (!std::getline(ss, r.frequency, ';') || r.frequency.empty()) throw std::runtime_error("����������� �����������");
            if (!std::getline(ss, r.period, ';') || r.period.empty()) throw std::runtime_error("������������ �����");
            if (!std::getline(ss, r.startArrive, ';') || r.startArrive.empty()) throw std::runtime_error("����������� �������� (���������)");
            if (!std::getline(ss, r.startDepart, ';') || r.startDepart.empty()) throw std::runtime_error("����������� ����������� (���������)");
            if (!std::getline(ss, r.endDepart, ';') || r.endDepart.empty()) throw std::runtime_error("����������� ����������� (������)");
            if (!std::getline(ss, r.endArrive, ';') || r.endArrive.empty()) throw std::runtime_error("����������� �������� (������)");

            routes.push_back(r);
        }
        catch (const std::exception& e) {
            std::cerr << "������� � ����� " << lineNumber << ": " << e.what() << "\n";
        }
    }
    fin.close();
    std::cout << "������� " << routes.size() << " �����.\n";
}

void ScheduleSystem::saveToFile() const {
    std::ofstream fout(filename);
    if (!fout) {
        std::cerr << "�� ������� �������� ����: " << filename << "\n";
        return;
    }
    for (const auto& r : routes) {
        fout << r.id << ";" << r.route << ";" << r.frequency << ";" << r.period << ";"
            << r.startArrive << ";" << r.startDepart << ";" << r.endDepart << ";" << r.endArrive << "\n";
    }
    fout.close();
    std::cout << "��� ��������� � ����: " << filename << "\n";
}

void ScheduleSystem::printSchedule() const {
    std::cout << "ʳ������ �����: " << routes.size() << "\n";
    if (routes.empty()) {
        std::cout << "������� ������� ��� �� �����������.\n";
        return;
    }

    for (const auto& r : routes) {
        std::cout << "ID: " << r.id << "\n"
            << "�������: " << r.route << "\n"
            << "�����������: " << r.frequency << "\n"
            << "����� 䳿: " << r.period << "\n"
            << "�������� (���������): " << r.startArrive << "\n"
            << "³���������� (���������): " << r.startDepart << "\n"
            << "³���������� (������): " << r.endDepart << "\n"
            << "�������� (������): " << r.endArrive << "\n"
            << "------------------------------------\n";
    }
}

void ScheduleSystem::searchByStation() const {
    std::string name;
    std::cout << "������ ����� ������� (��������� ��� ������): ";
    std::getline(std::cin, name);

    std::string lowered;
    std::transform(name.begin(), name.end(), std::back_inserter(lowered), ::tolower);

    bool found = false;
    for (const auto& r : routes) {
        std::string route_lower = r.route;
        std::transform(route_lower.begin(), route_lower.end(), route_lower.begin(), ::tolower);
        if (route_lower.find(lowered) != std::string::npos) {
            std::cout << "ID: " << r.id << " � " << r.route << " (" << r.frequency << ", " << r.period << ")\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "����� �� �������� �������� �� ��������.\n";
    }
}

void ScheduleSystem::addRoute() {
    BusRoute r;
    std::cout << "����� ����� (ID): ";
    std::cin >> r.id;
    std::cin.ignore();

    // �������� ���������� ID
    for (const auto& route : routes) {
        if (route.id == r.id) {
            std::cout << "���� � ����� ID ��� ����!\n";
            return;
        }
    }

    std::cout << "�������: "; std::getline(std::cin, r.route);
    std::cout << "�����������: "; std::getline(std::cin, r.frequency);
    std::cout << "����� 䳿: "; std::getline(std::cin, r.period);
    std::cout << "�������� (���������): "; std::getline(std::cin, r.startArrive);
    std::cout << "³���������� (���������): "; std::getline(std::cin, r.startDepart);
    std::cout << "³���������� (������): "; std::getline(std::cin, r.endDepart);
    std::cout << "�������� (������): "; std::getline(std::cin, r.endArrive);

    routes.push_back(r);
    std::cout << "���� ������.\n";
}

void ScheduleSystem::removeRoute() {
    int id;
    std::cout << "������ ����� ����� ��� ���������: ";
    std::cin >> id;
    std::cin.ignore();

    auto it = std::remove_if(routes.begin(), routes.end(), [id](const BusRoute& r) {
        return r.id == id;
        });

    if (it != routes.end()) {
        routes.erase(it, routes.end());
        std::cout << "���� ��������.\n";
    }
    else {
        std::cout << "���� �� ��������.\n";
    }
}