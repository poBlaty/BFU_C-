#include "Triangle.h"
#include <cmath>
using namespace mt;


Triangle::Triangle(float side1, float side2, float side3) {
    this->side_1 = side1;
    this->side_2 = side2;
    this->side_3 = side3;
}

float Triangle::getArea() { //Gerona
    float p = (this->side_1 + this->side_2 + this->side_3) / 2;
    return std::sqrt(p * (p - this->side_1) * (p - this->side_2) * (p - this->side_3));
}

float Triangle::getPerimeter() {
    return this->side_1 + this->side_2 + this->side_3;
}