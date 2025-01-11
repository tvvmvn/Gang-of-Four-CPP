#include <iostream>
#include <string>
using namespace std;

// Component
class Car {
  public:
    virtual string about() = 0;
};

// Concrete component
class Avante : public Car {
  public:
    string about() {
      return "Hyundai Avante";
    }
};

// Decorator interface
class CarDecorator : public Car {
  public:
    Car* car;
    CarDecorator(Car* c): car(c) {};

    string about() {
      return car->about();
    }
};

// Concrete decorator
class WingDecorator : public CarDecorator {
  public:
    WingDecorator(Car* c): CarDecorator(c) {}; 
    
    string about() {
      return car->about() + " plus wing";
    }
};

class CarbonDecorator : public CarDecorator {
  public:
    CarbonDecorator(Car* c): CarDecorator(c) {}; 
    
    string about() {
      return car->about() + " plus carbon";
    }
};

int main() {
  Car* avante = new Avante();
  Car* avanteWing = new WingDecorator(avante);
  Car* avanteWingCarbon = new CarbonDecorator(avanteWing);

  cout << avante->about() << endl; 
  cout << avanteWing->about() << endl; 
  cout << avanteWingCarbon->about() << endl; 

  delete avante;
  delete avanteWing;
  delete avanteWingCarbon;
}

/*
Output

Hyundai Avante
Hyundai Avante plus wing
Hyundai Avante plus wing plus carbon
*/