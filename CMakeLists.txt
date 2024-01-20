cmake_minimum_required(VERSION 3.27)
project(Project_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_1 main.cpp
        math-figures/Figure.h
        math-figures/Parallelogram.cpp
        math-figures/Parallelogram.h
        math-figures/Rectangle.cpp
        math-figures/Rectangle.h
        math-figures/Square.cpp
        math-figures/Square.h
        math-figures/Triangle.cpp
        math-figures/Triangle.h
        math-figures/Ellipse.cpp
        math-figures/Ellipse.h
        math-figures/RegularTetrahedron.cpp
        math-figures/RegularTetrahedron.h
        math-figures/Cone.cpp
        math-figures/Cone.h
        math-figures/Sphere.cpp
        math-figures/Sphere.h
        math-figures/RectangularParallelepiped.cpp
        math-figures/RectangularParallelepiped.h
        math-figures/Cube.cpp
        math-figures/Cube.h)
