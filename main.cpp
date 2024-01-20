#include <iostream>
#include <stdexcept>
#include <cmath>
#define PI 3.14159

class Figure{
    virtual float getArea() = 0;
public:
    ~Figure()=default;
};

class Figure2D : public Figure{
    virtual float getPerimeter() = 0;
};

class Figure3D : public Figure{
    virtual float getVolume() = 0;
};

//

class Parallelogram : public Figure2D{
public:
    Parallelogram(float side1, float side2, double _angle){
        if (_angle > 180 || _angle < 0){
            throw std::invalid_argument{"the angle is not within from 0 to 180"};
        }
        this->side_1 = side1;
        this->side_2 = side2;
        this->angle = _angle*PI/180; // to radians
    }

    float getArea() {
        return this->side_1 * this->side_2 * std::sin(this->angle);
    }

    float getPerimeter(){
        return 2 * (this->side_1 + this->side_2);
    }
protected:
    float side_1;
    float side_2;
    double angle;
};

class Rectangle : public Parallelogram{
public:
    Rectangle(float side1, float side2) : Parallelogram(side1, side2, 90) {}

    float getLengthDiagonal(){
        return std::pow(this->side_1, 2) + std::pow(this->side_2, 2);
    }

};

class Square : public Rectangle{
public:
    Square(float side1) : Rectangle(side1, side1) {}
};

//
class Triangle : public Figure2D{

    float side_1;
    float side_2;
    float side_3;
public:
    Triangle(float side1, float side2, float side3){
        this->side_1 = side1;
        this->side_2 = side2;
        this->side_3 = side3;
    }
    float getArea(){ //Gerona
        float p = (this->side_1 + this->side_2 + this->side_3) / 2;
        return std::sqrt(p * (p - this->side_1) * (p - this->side_2) * (p - this->side_3));
    }

    float getPerimeter(){
        return this->side_1 + this->side_2 + this->side_3;
    }
};

class Ellipse : public Figure2D{
    float r;
    float R;
public:
    Ellipse(float _r, float _R){
        this->r = _r;
        this->R = _R;
    }
    float getArea(){
        return PI * this->R * this->r;
    }

    float getPerimeter(){
        return 4*((PI*this->r*this->R + std::pow((this->R - this->r), 2))/(this->r + this->R));
    }
};

//
class RegularTetrahedron : public Figure3D{
    float side;

public:
    RegularTetrahedron(float _side){
        this->side = _side;
    };

    float getArea(){
        return std::sqrt(3) * this->side * this->side;
    }

    float getVolume(){
        return (std::sqrt(2) * std::pow(this->side, 3)) / 12;
    }
};

class Cone : public Figure3D{
    float edge;
    float r;
    float h;

public:
    Cone(float _edge, float _r, float _h){
        this->edge = _edge;
        this->r = _r;
        this->h = _h;
    }

    float getArea(){
        return PI * this->r * this->r + PI * this->r * this->edge;
    }

    float getVolume(){
        return (PI * this->r * this->r * this->h) / 3;
    }
};

class Sphere : public Figure3D{

    float r;
public:
    Sphere(float _r){
        this->r = _r;
    }

    float getArea(){
        return 4 * PI * this->r * this->r;
    }

    float getVolume(){
        return (4 * PI * std::pow(this->r,3) / 3);
    }
};

class RectangularParallelepiped : public Figure3D {
    float side_1;
    float side_2;
    float side_3;
public:
    RectangularParallelepiped(float s1, float s2, float s3){
        this->side_1 = s1;
        this->side_2 = s2;
        this->side_3 = s3;
    }

    float getArea(){
        float a = this->side_1;
        float b = this->side_2;
        float c = this->side_3;
        return 2*(a*b + b*c + c*a);
    }

    float getVolume(){
        return this->side_1 * this->side_2 * this->side_3;
    }

    float getLengthDiagonal(){
        float a = std::pow(this->side_1,2);
        float b = std::pow(this->side_2,2);
        float c = std::pow(this->side_3,2);
        return std::sqrt(a + b + c);
    }
};

class Cube : public RectangularParallelepiped{
public:
    Cube(float side) : RectangularParallelepiped(side,side,side){}
};

int main() {
    Parallelogram *p = new Parallelogram(4,5,30);
    std::cout << (*p).getPerimeter() << std::endl;
    Rectangle *r = new Rectangle(4, 5);
    std::cout << (*r).getLengthDiagonal() << std::endl;
    Square *s = new Square(5);
    std::cout << (*s).getLengthDiagonal() << std::endl;

}
