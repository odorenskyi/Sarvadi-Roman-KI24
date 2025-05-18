#pragma once
#include <string>
#include <vector>

struct BusRoute {
    int id;
    std::string route;
    std::string frequency;
    std::string period;
    std::string startArrive;
    std::string startDepart;
    std::string endDepart;
    std::string endArrive;
};

class ScheduleSystem {
    std::string filename;
    std::vector<BusRoute> routes;

public:
    ScheduleSystem(const std::string& file);
    void loadFromFile();
    void saveToFile() const;
    void printSchedule() const;
    void searchByStation() const;
    void addRoute();
    void removeRoute();
};