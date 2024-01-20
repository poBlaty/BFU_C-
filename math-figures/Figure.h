#ifndef PROJECT_1_FIGURE_H
#define PROJECT_1_FIGURE_H
#pragma once
//interfaces
namespace mt {
    class Figure {
        virtual float getArea() = 0;

    public:
        ~Figure() = default;
    };

    class Figure2D : public Figure {
        virtual float getPerimeter() = 0;
    };

    class Figure3D : public Figure {
        virtual float getVolume() = 0;
    };
}

#endif //PROJECT_1_FIGURE_H
