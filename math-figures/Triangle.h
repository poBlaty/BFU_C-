#pragma once
#ifndef PROJECT_1_TRIANGLE_H
#define PROJECT_1_TRIANGLE_H

#include "Figure.h"

namespace mt {
    class Triangle : public Figure2D {

        float side_1;
        float side_2;
        float side_3;
    public:
        Triangle(float side1, float side2, float side3);

        float getArea();

        float getPerimeter();
    };
}

#endif //PROJECT_1_TRIANGLE_H
