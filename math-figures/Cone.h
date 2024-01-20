#pragma once
#ifndef PROJECT_1_CONE_H
#define PROJECT_1_CONE_H

#include "Figure.h"

namespace mt {

    class Cone : public Figure3D {
        float edge;
        float r;
        float h;

    public:
        Cone(float _edge, float _r, float _h);

        float getArea();

        float getVolume();
    };

}

#endif //PROJECT_1_CONE_H
