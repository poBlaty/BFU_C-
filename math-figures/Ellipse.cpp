#include <cmath>
#include "Ellipse.h"
using namespace mt;

Ellipse::Ellipse(float _r, float _R) {
    this->r = _r;
    this->R = _R;
}

float Ellipse::getArea() {
    return PI * this->R * this->r;
}

float Ellipse::getPerimeter() {
    return 4 * ((PI * this->r * this->R + std::pow((this->R - this->r), 2)) / (this->r + this->R));
}