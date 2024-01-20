#include <iostream>
#include "math-figures/Square.h"
using namespace mt;

int main() {
    Parallelogram *p = new Parallelogram(4,5,30);
    std::cout << (*p).getPerimeter() << std::endl;
    Rectangle *r = new Rectangle(4, 5);
    std::cout << (*r).getLengthDiagonal() << std::endl;
    Square *s = new Square(5);
    std::cout << (*s).getLengthDiagonal() << std::endl;

}
