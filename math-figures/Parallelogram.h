#pragma once
#ifndef PROJECT_1_PARALLELOGRAM_H
#define PROJECT_1_PARALLELOGRAM_H

#include "Figure.h"

namespace mt {
    class Parallelogram : public Figure2D {
    public:
        Parallelogram(float side1, float side2, double _angle);

        float getArea();

        float getPerimeter();

    protected:
        float side_1;
        float side_2;
        double angle;
    };
}
#endif //PROJECT_1_PARALLELOGRAM_H
