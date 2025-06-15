#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>
#include <cmath>
#include "../ModulesSarvadi.h"

using namespace std;

struct TestSuite {
    float radius = 0;
    float height = 0;
    float expResult = 0;
};

vector<TestSuite> readCSVFiles(string filePath) {
    ifstream testSuite(filePath);
    vector<TestSuite> autotest;
    TestSuite ts;
    string line, value;

    getline(testSuite, line); // Пропускаємо заголовок

    while (getline(testSuite, line)) {
        stringstream s(line);
        vector<string> row;

        while (getline(s, value, ',')) {
            row.push_back(value);
        }

        ts.radius = stof(row[0]);
        ts.height = stof(row[1]);
        ts.expResult = stof(row[2]);

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

        vector<TestSuite> autotest = readCSVFiles("..\\..\\TestSuite\\TS.txt");

        for (int i = 0; i < autotest.size(); i++) {
            ClassLab12_Sarvadi cone(autotest[i].radius, autotest[i].height);

            if (round(autotest[i].expResult) == round(cone.getVolumeCone())) {
                testResult << "test №" << i + 1 << " -> passed" << endl << endl;
            }
            else {
                testResult << "test №" << i + 1 << " -> failed" << endl
                    << "answers don't match" << endl
                    << "It should be -> " << autotest[i].expResult << endl
                    << "Received response -> " << cone.getVolumeCone() << endl << endl;
            }
        }
    }

    testResult.close();
    system("pause");
    return 0;
}
