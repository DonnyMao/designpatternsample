#include <iostream>
#include <string>
using namespace std;

// Sub system: Shape Basic Class
class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}

    virtual void draw() = 0;
};

// Sub system 1: Rectangle
class Rectangle: public Shape
{
public:
    void draw() override
    {
        cout << "Draw a rectangle" << endl;
    }
};

// Sub system 2: Triangle
class Triangle: public Shape
{
public:
    void draw() override
    {
        cout << "Draw a triangle" << endl;
    }
};

// Sub system 3: Circle
class Circle: public Shape
{
public:
    void draw() override
    {
        cout << "Draw a circle" << endl;
    }
};

// Facade: Complex shape maker
class ComplexShape
{
public:
    ComplexShape() 
    {
        m_rectangle = new Rectangle();
        m_triangle  = new Triangle();
        m_circle    = new Circle();
    }
    ~ComplexShape() 
    {
        delete m_rectangle;
        m_rectangle = nullptr;
        delete m_triangle;
        m_triangle = nullptr;
        delete m_circle;
        m_circle = nullptr;
    }

    void drawRoundedRectangleShape()
    {
        m_rectangle->draw();
        m_circle->draw();
        cout << "Cut additional parts to make a rounded rectangle!" << endl;
    }

    void drawSpireHouseShape()
    {
        m_rectangle->draw();
        m_triangle->draw();
        cout << "Stich two basic shapes to make a spire house!" << endl;
    }

private:
    Rectangle* m_rectangle;
    Triangle*  m_triangle;
    Circle*    m_circle;
};

int main()
{
    cout << "Main function starts here!" << endl;
    ComplexShape* complexShape = new ComplexShape();
    complexShape->drawRoundedRectangleShape();
    complexShape->drawSpireHouseShape();

    delete complexShape;
    complexShape = nullptr;

    return 0;
}