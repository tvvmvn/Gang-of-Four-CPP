#include <iostream>
#include <string>
using namespace std;


class Rectangle {
  public:
    int width;
    int height;

    int getSize() {
      return width * height;
    }
};

// Derived classes must be substitutable for their base class.
// and this is violation
class Square : public Rectangle {
  public:
    int getSize() {
      return width * width;
    }
};

