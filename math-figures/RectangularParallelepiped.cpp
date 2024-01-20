#include <cmath>
#include "RectangularParallelepiped.h"

using namespace mt;

RectangularParallelepiped::RectangularParallelepiped(float s1, float s2, float s3) {
    this->side_1 = s1;
    this->side_2 = s2;
    this->side_3 = s3;
}

float RectangularParallelepiped::getArea() {
    float a = this->side_1;
    float b = this->side_2;
    float c = this->side_3;
    return 2 * (a * b + b * c + c * a);
}

float RectangularParallelepiped::getVolume() {
    return this->side_1 * this->side_2 * this->side_3;
}

float RectangularParallelepiped::getLengthDiagonal() {
    float a = std::pow(this->side_1, 2);
    float b = std::pow(this->side_2, 2);
    float c = std::pow(this->side_3, 2);
    return std::sqrt(a + b + c);
}