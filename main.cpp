#include <iostream>
#include <cmath>

class Point {
protected:
    double x, y;
public:
    Point(const double x, const double y){
        this->x = x;
        this->y = y;
    }
    void print_point() const{
        std::cout << "(" << x << " ," << y << ")" << std::endl;
    }
};

//Factory Method
class PointFactory{
public:
    virtual Point CreatePoint(double x, double y) = 0;
};

class CartesianCreate: public PointFactory{
public:
    Point CreatePoint(const double x, const double y) final{
        Point p(x, y);
        return p;
    }
    // We also implement a static method so that we can create a point without creating an object.
    static Point NewCartesian(const double x, const double y){
        Point p(x, y);
        return p;
    }
};

class PolarCreate: public PointFactory{
public:
    Point CreatePoint(const double r, const double phi) final{
        Point p(r * cos(phi), r * sin(phi));
        return p;
    }
    // We also implement a static method so that we can create a point without creating an object.
    static Point NewPolar(const double r, const double phi){
        Point p(r * cos(phi), r * sin(phi));
        return p;
    }
};

//Simple factory
class SimplePointFactory{
public:
    static Point CreateCartesian(const double x, const double y){
        Point p(x, y);
        return p;
    }
    static Point CreatePolar(const double r, const double phi){
        Point p(r * cos(phi), r * sin(phi));
        return p;
    }
    static Point CreatePoint(const double f, const double s, const std::string type){
        if (type == "Cartesian"){
            Point p(f, s);
            return p;
        }
        if (type == "Polar"){
            Point p(f * cos(s), f * sin(s));
            return p;
        }
        Point p(0, 0);
        return p;
    }
};



int main() {
    CartesianCreate car_c;
    PolarCreate pol_c;

    Point p1 = car_c.CreatePoint(5, 3);
    Point p2 = pol_c.CreatePoint(10, M_PI_4);
    Point p3 = PolarCreate::NewPolar(32, 3 * M_PI_4);
    Point p4 = CartesianCreate::NewCartesian(-M_2_PI, 1.5*M_2_PI);
    Point p5 = SimplePointFactory::CreatePoint(-8, 9, "Cartesian");
    Point p6 = SimplePointFactory::CreatePoint(7, 3 * M_2_PI, "Polar");
    Point p7 = SimplePointFactory::CreateCartesian(-3.14, 2.71);
    Point p8 = SimplePointFactory::CreatePolar(10, 3.1415);

    p1.print_point();
    p2.print_point();
    p3.print_point();
    p4.print_point();
    p5.print_point();
    p6.print_point();
    p7.print_point();
    p8.print_point();

    return 0;
}
