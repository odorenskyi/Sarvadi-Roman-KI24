#ifndef MODULESSARVADI_H_INCLUDED
#define MODULESSARVADI_H_INCLUDED

#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class ClassLab12_Sarvadi {
public:
    ClassLab12_Sarvadi() {}
    ClassLab12_Sarvadi(float radius, float height);

    void setRadius(float radius);
    void setHeight(float height);

    float getRadius() const;
    float getHeight() const;

    float getVolumeCone() const;

private:
    float radius = 0.0;
    float height = 0.0;
};

ClassLab12_Sarvadi::ClassLab12_Sarvadi(float radius, float height) {
    this->radius = radius;
    this->height = height;
}

void ClassLab12_Sarvadi::setRadius(float radius) {
    this->radius = radius;
}

void ClassLab12_Sarvadi::setHeight(float height) {
    this->height = height;
}

float ClassLab12_Sarvadi::getRadius() const {
    return radius;
}

float ClassLab12_Sarvadi::getHeight() const {
    return height;
}

float ClassLab12_Sarvadi::getVolumeCone() const {
    return (M_PI * radius * radius * height) / 3.0;
}

#endif // MODULESSARVADI_H_INCLUDED
