#include <cmath>
#include <stdexcept>
#include "Rectangle.h"
using namespace mt;

Rectangle::Rectangle(float side1, float side2) : Parallelogram(side1, side2, 90) {};

float Rectangle::getLengthDiagonal() {
    return std::pow(this->side_1, 2) + std::pow(this->side_2, 2);
}