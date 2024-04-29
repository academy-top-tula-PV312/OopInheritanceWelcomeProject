#include <iostream>
#include <string>

class Point
{
    int x;
    int y;
public:
    Point() : x{}, y{} 
    {
        std::cout << "point construct\n";
    }
    Point(int x, int y) : x{ x }, y{ y } 
    {
        std::cout << "point construct\n";
    }
    ~Point()
    {
        std::cout << "point destruct\n";
    }

    int& X() { return x; }
    int& Y() { return y; }

    std::string ToString() 
    {
        return "(" + std::to_string(x)
            + "," + std::to_string(y) + ")";
    }
};

class Shape
{
    Point point;
public:
    Shape(int x, int y);
    Shape(Point point);
    Shape();

    Point& ShapePoint();
};

class Rectangle : public Shape
{
    int width;
    int height;
public:
    Rectangle(Point point, int width, int height);
    Rectangle(int x, int y, int width, int height);
};

class Circle : public Shape
{
    int radius;

};

int main()
{

    
}

Shape::Shape(int x, int y) : point{ Point(x,y) } 
{
    //point = Point(x, y);
}

Shape::Shape(Point point) : point{ point } {}
Shape::Shape() : Shape(0, 0) {}

Point& Shape::ShapePoint(){ return point; }

Rectangle::Rectangle(Point point, int width, int height)
    : Shape(point), width{ width }, height{ height }
{
    /*Shape(point);
    this->width = width;
    this->height = height;*/
}

Rectangle::Rectangle(int x, int y, int width, int height)
    : Shape(x, y), width{ width }, height{ height } {}
