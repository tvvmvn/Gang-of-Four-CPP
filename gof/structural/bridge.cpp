#include <iostream>
using namespace std;

// Abstraction
class Shape {
  public:
    virtual void draw() = 0;
};

// Concrete abstractions
class Circle : public Shape {
  private:
    Renderer& renderer;

  public:
    Circle(Renderer& renderer) : renderer(renderer) {}

    void draw() override {
      cout << "Drawing a circle ";
      
      renderer.render();
    }
  };

class Square : public Shape {
  private:
    Renderer& renderer;

  public:
    Square(Renderer& renderer) : renderer(renderer) {}

    void draw() override {
      cout << "Drawing a square ";
      
      renderer.render();
    }
};

// Implementations
class Renderer {
  public:
    virtual void render() = 0;
};

// Concrete implementations
class VectorRenderer : public Renderer {
  public:
    void render() override {
      cout << "Rendering as a vector\n";
    }
};

class RasterRenderer : public Renderer {
  public:
    void render() override {
      cout << "Rendering as a raster\n";
    }
};

int main() {
  VectorRenderer vectorRenderer;
  RasterRenderer rasterRenderer;

  Circle circle(vectorRenderer);
  Square square(rasterRenderer);

  circle.draw(); 
  square.draw(); 
           
  return 0;
}


/*
Output

Drawing a circle Rendering as a vector
Drawing a square Rendering as a raster
*/
