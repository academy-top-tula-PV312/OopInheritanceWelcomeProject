#include <iostream>
#include <string>

class Point
{
    int x;
    int y;
public:
    Point() : x{}, y{} 
    {
        //std::cout << "point construct\n";
    }
    Point(int x, int y) : x{ x }, y{ y } 
    {
        //std::cout << "point construct\n";
    }
    ~Point()
    {
        //std::cout << "point destruct\n";
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
protected:
    Point point;
public:
    Shape(int x, int y);
    Shape(Point point);
    Shape();

    Point& ShapePoint();

    virtual int Area() = 0;
    //virtual int Area(int) { return 10; }
    virtual int Perimetr() = 0;

    std::string ToString();
};

class Rectangle : public Shape
{
    int width;
    int height;
public:
    Rectangle(Point point, int width, int height);
    Rectangle(int x, int y, int width, int height);

    int Area() override;
    int Perimetr();

    std::string ToString();
};

class Circle : public Shape
{
    int radius;
public:
    Circle();
    Circle(int x, int y, int radius);
    Circle(Point point, int radius);

    int Area();
    int Perimetr();

    std::string ToString();
};

//class Ellipse : public Circle
//{
//public:
//    Ellipse()
//    {
//        
//    }
//};

int main()
{
    Rectangle* rect1 = new Rectangle(1, 1, 10, 20);
    std::cout << rect1->Perimetr() << "\n";
    std::cout << rect1->ToString() << "\n";
    
    Circle* circle1 = new Circle(2, 2, 10);
    std::cout << circle1->Perimetr() << "\n";
    std::cout << circle1->ToString() << "\n";

    Shape* shape = rect1;
    std::cout << shape->Perimetr() << "\n";

    shape = circle1;
    std::cout << shape->Perimetr() << "\n";

}

//-----------------------------------------------
Shape::Shape(int x, int y) : point{ Point(x,y) } 
{
    //point = Point(x, y);
}

Shape::Shape(Point point) : point{ point } {}
Shape::Shape() : Shape(0, 0) {}

Point& Shape::ShapePoint(){ return point; }

std::string Shape::ToString()
{
    return "x: " + std::to_string(point.X())
        + ", y: " + std::to_string(point.Y());
}

//-----------------------------------------------

Rectangle::Rectangle(Point point, int width, int height)
    : Shape(point), width{ width }, height{ height }
{
    /*Shape(point);
    this->width = width;
    this->height = height;*/
}

Rectangle::Rectangle(int x, int y, int width, int height)
    : Shape(x, y), width{ width }, height{ height } {}

int Rectangle::Area(){ return width * height; }
int Rectangle::Perimetr() { return 2 * (width + height); }

std::string Rectangle::ToString()
{
    return Shape::ToString()
        + ", width: " + std::to_string(width)
        + ", height: " + std::to_string(height);

}

//-----------------------------------------------

Circle::Circle() : Shape(), radius{} {}

Circle::Circle(Point point, int radius)
    : Shape(point), radius{ radius } {}

Circle::Circle(int x, int y, int radius)
    : Shape(x, y), radius{ radius } {}

int Circle::Area() { return 3.14 * radius * radius; }
int Circle::Perimetr() { return 3.14 * 2 * radius; }

std::string Circle::ToString()
{
    return Shape::ToString()
        + ", radius: " + std::to_string(radius);
}


