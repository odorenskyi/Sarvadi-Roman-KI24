
#include <cmath>
#include <stdexcept>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double calculateS(double x, double y, double z) {
    if (x < 0) {
        throw std::invalid_argument("x має бути >= 0 для sqrt(x)");
    }

    double sinPart = std::sin(std::abs(y - z * z));
    double sqrtX = std::sqrt(x);

    double rootInner = std::pow(y * z, x) + y / (2 * M_PI);
    if (rootInner < 0) {
        throw std::domain_error("Підкореневий вираз менший за 0");
    }

    double sqrtPart = std::sqrt(rootInner);

    double S = std::abs(sinPart + sqrtX - sqrtPart);

    return S;
}