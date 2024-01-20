#pragma once
#ifndef PROJECT_1_ELLIPSE_H
#define PROJECT_1_ELLIPSE_H

#include "Figure.h"
#define PI 3.14159

namespace mt {

    class Ellipse : public Figure2D {
        float r;
        float R;
    public:
        Ellipse(float _r, float _R);

        float getArea();

        float getPerimeter();
    };

}

#endif //PROJECT_1_ELLIPSE_H
