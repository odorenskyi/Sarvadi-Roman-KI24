#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>
#include <cmath>
#include "ModulesSarvadi.h"

using namespace std;

struct TestSuite {
    float action = 0;
    float expResult = 0;
};

vector<TestSuite> readCSVFile(string filePath) {
    ifstream testSuite(filePath);
    vector<string> row;
    vector<TestSuite> autotest;
    TestSuite ts;
    string line, value;
    getline(testSuite, line); // Пропускаємо заголовок

    while (getline(testSuite, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, value, ',')) {
            row.push_back(value);
        }

        ts.action = stof(row[0]);
        ts.expResult = stof(row[1]);

        autotest.push_back(ts);
    }

    testSuite.close();
    return autotest;
}

int main() {
    ofstream testResult;
    string pathFile = __FILE__;
    size_t found = pathFile.find("\\Lab12\\prj");

    if (found == string::npos) {
        testResult.open("TestResult.txt");
        if (!testResult.is_open()) return -1;
        for (int i = 0; i < 100; i++) {
            cout << '\a';
        }
        testResult << "Встановлені вимоги порядку виконання лабораторної роботи порушено!";
    }
    else {
        testResult.open("..\\..\\TestSuite\\TestResult.txt");
        if (!testResult.is_open()) return -1;

        ClassLab12_Sarvadi sphere(0);
        vector<TestSuite> autotest = readCSVFile("..\\..\\TestSuite\\TS.txt");

        for (int i = 0; i < autotest.size(); i++) {
            sphere.setRadius(autotest[i].action);
            if (round(autotest[i].expResult) == round(sphere.getAreaSphere())) {
                testResult << "test №" << i + 1 << " -> passed" << endl << endl;
            }
            else {
                testResult << "test №" << i + 1 << " -> failed" << endl
                    << "answers don't match" << endl
                    << "It should be -> " << autotest[i].expResult << endl
                    << "Received response -> " << sphere.getAreaSphere() << endl << endl;
            }
        }
    }

    testResult.close();
    system("pause");
    return 0;
}
