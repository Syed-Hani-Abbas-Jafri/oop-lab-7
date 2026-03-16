#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string position;
    string color;
    double borderThickness;

public:
    Shape(string pos, string col, double border)
    {
        position        = pos;
        color           = col;
        borderThickness = border;
    }

    virtual void draw()
    {
        cout << "Drawing a generic shape" << endl;
    }

    virtual double calculateArea()
    {
        return 0;
    }

    virtual double calculatePerimeter()
    {
        return 0;
    }

    virtual void printInfo()
    {
        cout << "Position         : " << position        << endl;
        cout << "Color            : " << color           << endl;
        cout << "Border Thickness : " << borderThickness << endl;
    }
};


class Circle : public Shape {
private:
    double radius;

public:
    Circle(string pos, string col, double border, double r)
        : Shape(pos, col, border)
    {
        radius = r;
    }

    void draw() override
    {
        cout << "Drawing circle at " << position << " with color " << color << endl;
    }

    double calculateArea() override
    {
        return 3.1416 * radius * radius;
    }

    double calculatePerimeter() override
    {
        return 2 * 3.1416 * radius;
    }

    void printInfo() override
    {
        cout << "\nCircle info" << endl;
        Shape::printInfo();
        cout << "Radius           : " << radius                << endl;
        cout << "Area             : " << calculateArea()       << endl;
        cout << "Perimeter        : " << calculatePerimeter()  << endl;
    }
};


class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(string pos, string col, double border, double w, double h)
        : Shape(pos, col, border)
    {
        width  = w;
        height = h;
    }

    void draw() override
    {
        cout << "Drawing rectangle at " << position << " with color " << color << endl;
    }

    double calculateArea() override
    {
        return width * height;
    }

    double calculatePerimeter() override
    {
        return 2 * (width + height);
    }

    void printInfo() override
    {
        cout << "\nRectangle info" << endl;
        Shape::printInfo();
        cout << "Width            : " << width               << endl;
        cout << "Height           : " << height              << endl;
        cout << "Area             : " << calculateArea()     << endl;
        cout << "Perimeter        : " << calculatePerimeter()<< endl;
    }
};


class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(string pos, string col, double border, double s1, double s2, double s3)
        : Shape(pos, col, border)
    {
        a = s1;
        b = s2;
        c = s3;
    }

    void draw() override
    {
        cout << "Drawing triangle at " << position << " with color " << color << endl;
    }

    double calculatePerimeter() override
    {
        return a + b + c;
    }

    double calculateArea() override
    {
        double s = calculatePerimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void printInfo() override
    {
        cout << "\nTriangle info" << endl;
        Shape::printInfo();
        cout << "Sides            : " << a << ", " << b << ", " << c << endl;
        cout << "Area             : " << calculateArea()      << endl;
        cout << "Perimeter        : " << calculatePerimeter() << endl;
    }
};


class Polygon : public Shape {
private:
    int    sides;
    double sideLength;

public:
    Polygon(string pos, string col, double border, int s, double len)
        : Shape(pos, col, border)
    {
        sides      = s;
        sideLength = len;
    }

    void draw() override
    {
        cout << "Drawing polygon with " << sides << " sides at " << position << endl;
    }

    double calculatePerimeter() override
    {
        return sides * sideLength;
    }

    double calculateArea() override
    {
        return (sides * sideLength * sideLength) / (4 * tan(3.1416 / sides));
    }

    void printInfo() override
    {
        cout << "\nPolygon info" << endl;
        Shape::printInfo();
        cout << "Sides            : " << sides               << endl;
        cout << "Side Length      : " << sideLength          << endl;
        cout << "Area             : " << calculateArea()     << endl;
        cout << "Perimeter        : " << calculatePerimeter()<< endl;
    }
};


int main()
{
    Circle    c("center(5,5)",    "red",    2,   7);
    Rectangle r("topLeft(0,0)",   "blue",   1.5, 10, 5);
    Triangle  t("point(2,3)",     "green",  1,   3, 4, 5);
    Polygon   p("origin(0,0)",    "yellow", 1,   6, 4);

    cout << "\n/-/-/-/-/-/- shape design tool /-/-/-/-/-/-" << endl;

    c.draw();
    c.printInfo();

    cout << "\n/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-" << endl;

    r.draw();
    r.printInfo();

    cout << "\n/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-" << endl;

    t.draw();
    t.printInfo();

    cout << "\n/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-" << endl;

    p.draw();
    p.printInfo();

    return 0;
}
