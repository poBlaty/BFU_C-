#include <cmath>
#include "Cone.h"
#define PI 3.14159

using namespace mt;

Cone::Cone(float _edge, float _r, float _h) {
    this->edge = _edge;
    this->r = _r;
    this->h = _h;
}

float Cone::getArea() {
    return PI * this->r * this->r + PI * this->r * this->edge;
}

float Cone::getVolume() {
    return (PI * this->r * this->r * this->h) / 3;
}