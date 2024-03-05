#include "point.h"
#include <iostream>
using namespace std;

class Rectangle{
    public:
        Rectangle(const POINT& point1, const POINT& point2) : p1(point1), p2(point2) {}
        POINT p1, p2;
        int edge1 = std::abs(p2.get_X() - p1.get_X());
        int edge2 = std::abs(p2.get_Y() - p1.get_Y());
        double aire(){
            return edge1*edge2;
        }
        double perimetre(){
            return 2*(edge1+edge2);
        }
};
class Cercle {
public:
    POINT center;
    double radius;

    Cercle(const POINT& center, double radius) : center(center), radius(radius) {}

    double aire() {
        return M_PI * radius * radius;
    }

    double circumference() {
        return 2 * M_PI * radius;
    }
};

class Carre {
public:
    POINT p1, p2; // Two points to define the diagonal of the square

    Carre(const POINT& point1, const POINT& point2) : p1(point1), p2(point2) {}

    double aire() {
        int edge = std::abs(p2.get_X() - p1.get_X());
        return edge * edge;
    }

    double perimetre() {
        int edge = std::abs(p2.get_X() - p1.get_X());
        return 4 * edge;
    }
};


int main(){
    POINT point1(1, 2);
    POINT point2(4, 6);
    POINT center(0,0);
    double radius = 7.0;

    Rectangle myRectangle(point1, point2);
    std::cout << "Rectangle P1: (" << point1.get_X() << ", " << point1.get_Y() << ")" << std::endl;
    std::cout << "Rectangle P2: (" << point2.get_X() << ", " << point2.get_Y() << ")" << std::endl;
    std::cout << "Area: " << myRectangle.aire() << std::endl;
    std::cout << "Perimeter: " << myRectangle.perimetre() << std::endl;

    Carre myCarre(point1,point2);
    std::cout << "Carre P1: (" << point1.get_X() << ", " << point1.get_Y() << ")" << std::endl;
    std::cout << "Carre P2: (" << point2.get_X() << ", " << point2.get_Y() << ")" << std::endl;
    std::cout << "Area: " << myCarre.aire() << std::endl;
    std::cout << "Perimeter: " << myCarre.perimetre() << std::endl;

    
    Cercle myCercle(center,radius);
    std::cout << "Circle Center: (" << center.get_X() << ", " << center.get_Y() << ")" << std::endl;
    std::cout << "Circle Radius: " << radius << std::endl;
    std::cout << "Circle Area: " << myCercle.aire() << std::endl;
    std::cout << "Circle Circumference: " << myCercle.circumference() << std::endl;
}



