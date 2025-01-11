#include <iostream>
#include <string>
using namespace std;

// Abstract class or interface(Java)
class FlyingObject {
  public:
    virtual void fly() = 0;
};

// implementation
class Plane : public FlyingObject {
  public:
    void fly() {
      cout << "It can fly with technology";
    }
};

// implementation
class Bird : public FlyingObject {
  public:
    void fly() {
      cout << "It can fly with wings";
    }
};