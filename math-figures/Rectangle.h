#pragma once
#ifndef PROJECT_1_RECTANGLE_H
#define PROJECT_1_RECTANGLE_H
#include "Parallelogram.h"

namespace mt {

    class Rectangle : public Parallelogram {
    public:
        Rectangle(float side1, float side2);

        float getLengthDiagonal();
    };
} // mt

#endif //PROJECT_1_RECTANGLE_H
