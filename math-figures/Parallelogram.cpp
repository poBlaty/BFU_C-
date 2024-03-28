#include <cmath>
#include <stdexcept>
#include "Parallelogram.h"
#define PI 3.14159
using namespace mt;

Parallelogram::Parallelogram(float side1, float side2, double _angle){
    if (_angle > 180 || _angle < 0) {
        throw std::invalid_argument{"the angle is not within from 0 to 180"};
    }
    if (side1 <= 0 || side2 <= 0) {
        throw std::invalid_argument{"Any sides is less or equal 0"};
    }
    this->side_1 = side1;
    this->side_2 = side2;
    this->angle = _angle * PI / 180; // to radians
}

float Parallelogram::getArea() {
    return this->side_1 * this->side_2 * std::sin(this->angle);
}

float Parallelogram::getPerimeter() {
    return 2 * (this->side_1 + this->side_2);
}