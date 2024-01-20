#pragma once
#ifndef PROJECT_1_REGULARTETRAHEDRON_H
#define PROJECT_1_REGULARTETRAHEDRON_H

#include "Figure.h"

namespace mt {

    class RegularTetrahedron : public Figure3D {
        float side;

    public:
        RegularTetrahedron(float _side);

        float getArea();

        float getVolume();
    };

} // mt

#endif //PROJECT_1_REGULARTETRAHEDRON_H
