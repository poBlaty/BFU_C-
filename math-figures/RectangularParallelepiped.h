#pragma once
#ifndef PROJECT_1_RECTANGULARPARALLELEPIPED_H
#define PROJECT_1_RECTANGULARPARALLELEPIPED_H

#include "Figure.h"
namespace mt {

    class RectangularParallelepiped : public Figure3D {
        float side_1;
        float side_2;
        float side_3;
    public:
        RectangularParallelepiped(float s1, float s2, float s3);

        float getArea();

        float getVolume();

        float getLengthDiagonal();
    };

} // mt

#endif //PROJECT_1_RECTANGULARPARALLELEPIPED_H
