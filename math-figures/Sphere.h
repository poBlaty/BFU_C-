#pragma once
#ifndef PROJECT_1_SPHERE_H
#define PROJECT_1_SPHERE_H

#include "Figure.h"
namespace mt {

    class Sphere : public Figure3D {
        float r;
    public:
        Sphere(float _r);

        float getArea();

        float getVolume();
    };

} // mt

#endif //PROJECT_1_SPHERE_H
