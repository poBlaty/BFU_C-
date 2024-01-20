#include <cmath>
#include "Sphere.h"
#define PI 3.14159

using namespace mt;

Sphere::Sphere(float _r) {
    this->r = _r;
}

float Sphere::getArea() {
    return 4 * PI * this->r * this->r;
}

float Sphere::getVolume() {
    return (4 * PI * std::pow(this->r, 3) / 3);
}