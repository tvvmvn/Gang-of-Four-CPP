#include <iostream>
#include <vector>
using namespace std;

class Circle;
class Square;
 
// Visitor interface
class ShapeVisitor {
  public:
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Square& square) = 0;
};
 
// Concrete Visitor
class DrawingVisitor : public ShapeVisitor {
  public:
    void visit(Circle& circle) override {
      cout << "Drawing a Circle\n";
    }
  
    void visit(Square& square) override {
      cout << "Drawing a Square\n";
    }
};
 
// Concrete Visitor
class AreaVisitor : public ShapeVisitor {
  public:
    void visit(Circle& circle) override {
      cout << "Calculating area of Circle\n";
    }
  
    void visit(Square& square) override {
      cout << "Calculating area of Square\n";
    }
};


// Element interface
class Shape {
  public:
    virtual void accept(ShapeVisitor& visitor) = 0;
};
 
// Concrete Element
class Circle : public Shape {
  public:
    void accept(ShapeVisitor& visitor) override {
      visitor.visit(*this);
    }
};
 
// Concrete Element
class Square : public Shape {
  public:
    void accept(ShapeVisitor& visitor) override {
      visitor.visit(*this);
    }
};

// Object Structure
class ShapeContainer {
  private:
    vector<Shape*> shapes;

  public:
    void addShape(Shape* shape) {
      shapes.push_back(shape);
    }
  
    void performOperations(ShapeVisitor& visitor) {
      for (Shape* shape : shapes) {
        shape->accept(visitor);
      }
    }
};
 
// Client
int main() {
  // Create instances of shapes
  Circle circle;
  Square square;
 
  // Create a container and add shapes to it
  ShapeContainer container;
  container.addShape(&circle);
  container.addShape(&square);
 
  // Create visitors
  DrawingVisitor visitorToDraw;
  AreaVisitor visitorToArea;
 
  // Perform operations like drawing or caculating
  container.performOperations(visitorToDraw);
  container.performOperations(visitorToArea);
 
  return 0;
}

/*
Output

Drawing a Circle
Drawing a Square

Calculating area of Circle
Calculating area of Square
*/