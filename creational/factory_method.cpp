#include <iostream>
#include <string>
using namespace std;

// Interface: Product
class Car {
  public:
    virtual void drive() = 0;
};

// Concrete product
class Avante : public Car {
  public:
    void drive() {
      cout << "Avante is driving";
    }
};

// Concrete product
class XM3 : public Car {
  public:
    void drive() {
      cout << "XM3 is driving";
    }
};

// Interface: Creator
class CarFactory {
  public:
    virtual Car* factoryMethod() = 0;
};

// Concrete creator
class AvanteFactory : public CarFactory {
  public:
    Car* factoryMethod() {
      return new Avante();
    }
};

// Concrete creator
class XM3Factory : public CarFactory {
  public:
    Car* factoryMethod() {
      return new XM3();
    }
};

// Client
int main() {
  CarFactory* avanteFactory = new AvanteFactory();
  CarFactory* xm3Factory = new XM3Factory();

  Car* avante = avanteFactory->factoryMethod();
  Car* xm3 = xm3Factory->factoryMethod();

  avante->drive(); 
  xm3->drive(); 

  delete avanteFactory;
  delete xm3Factory;
  delete avante;
  delete xm3;

  return 0;
}

/*
Output

Avante is driving
XM3 is driving
*/