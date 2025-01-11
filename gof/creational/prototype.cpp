#include <iostream>
#include <string>
using namespace std;

// Prototype Interface: Shape
class Shape {
  public:
    // Clone method for creating copies.
    virtual Shape* clone() const = 0;
    // Draw method for rendering the shape. 
    virtual void draw() const = 0;   
    // Virtual destructor for proper cleanup.
    virtual ~Shape() {}              
};

// Concrete Prototype: Circle
class Circle : public Shape {
  private:
    double radius;
 
  public:
    Circle(double r) : radius(r) {}
 
    Shape* clone() const override {
      return new Circle(*this);
    }
 
    void draw() const override {
      cout << "Drawing a circle with radius " << radius << endl;
    }
};

// Concrete Prototype: Rectangle
class Rectangle : public Shape {
  private:
    double width;
    double height;
 
  public:
    Rectangle(double w, double h) : width(w), height(h) {}
 
    Shape* clone() const override {
      return new Rectangle(*this);
    }
 
    void draw() const override {
      cout << "Drawing a rectangle with " << width << " * " << height << endl;
    }
};

int main() {
  // Creates prototypes
  Circle circlePrototype(5.0);
  Rectangle rectanglePrototype(4.0, 6.0);

  // clone prototypes
  Shape* shape1 = circlePrototype.clone();
  Shape* shape2 = rectanglePrototype.clone();

  // Usage of cloned objects
  shape1->draw(); 
  shape2->draw(); 
}

/*
Output

Drawing a circle with radius 5
Drawing a rectangle with 4 * 6
*/