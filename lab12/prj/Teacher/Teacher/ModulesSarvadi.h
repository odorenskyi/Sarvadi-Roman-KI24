#ifndef MODULESSARVADI_H_INCLUDED
#define MODULESSARVADI_H_INCLUDED
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <cmath>

class ClassLab12_Sarvadi {
public:
    ClassLab12_Sarvadi() {}
    ClassLab12_Sarvadi(float radius);
    void setRadius(float radius);
    float getRadius();
    float getAreaSphere();
private:
    float radius = 0.0;
};

ClassLab12_Sarvadi::ClassLab12_Sarvadi(float radius) {
    this->radius = radius;
}

void ClassLab12_Sarvadi::setRadius(float radius) {
    this->radius = radius;
}

float ClassLab12_Sarvadi::getRadius() {
    return radius;
}

float ClassLab12_Sarvadi::getAreaSphere() {
    return 4 * M_PI * pow(radius, 2);
}

#endif // MODULESSARVADI_H_INCLUDED
#pragma once
