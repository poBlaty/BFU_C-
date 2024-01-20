#include <cmath>
#include "RegularTetrahedron.h"
using namespace mt;

RegularTetrahedron::RegularTetrahedron(float _side) {
    this->side = _side;
};

float RegularTetrahedron::getArea() {
    return std::sqrt(3) * this->side * this->side;
}

float RegularTetrahedron::getVolume() {
    return (std::sqrt(2) * std::pow(this->side, 3)) / 12;
}