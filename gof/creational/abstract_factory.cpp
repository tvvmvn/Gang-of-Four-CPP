#include <iostream>
#include <string>
using namespace std;

// Abstract Product Interface for Cars
class Car {
  public:
    virtual void assemble() = 0;
};

// Concrete Product for Sedan Car
class Sedan : public Car {
  public: 
    void assemble() {
      cout << "Assembling Sedan car.\n";
    }
};

// Concrete Product for Hatchback Car
class Hatchback : public Car {
  public:
    void assemble() {
      cout << "Assembling Hatchback car.\n";
    }
};

// Abstract Product Interface for Car Specifications
class CarSpecification {
  public:
    virtual void display() = 0;
};

// Concrete Product for North America Car Specification
class NorthAmericaSpecification : public CarSpecification {
  public:  
    void display() {
      cout << "North America Car Specification: Safety features compliant with local regulations.\n";
    }
};

// Concrete Product for Europe Car Specification
class EuropeSpecification : public CarSpecification {
  public:
    void display() {
      cout << "Europe Car Specification: Fuel efficiency and emissions compliant with EU standards.\n";
    }
};

// Abstract Factory
class CarFactory {
  public:
    virtual Car* createCar() = 0;
    virtual CarSpecification* createSpecification() = 0;
};

// Concrete Factory for North America Cars
class NorthAmericaCarFactory : public CarFactory {
  public:
    Car* createCar() {
      return new Sedan();
    }

    CarSpecification* createSpecification() {
      return new NorthAmericaSpecification();
    }
};

// Concrete Factory for Europe Cars
class EuropeCarFactory : public CarFactory {
  public:
    Car* createCar() {
      return new Hatchback();
    }

    CarSpecification* createSpecification() {
      return new EuropeSpecification();
    }
};

// Client Code 
int main() {
  // Factories
  CarFactory* northAmericaFactory = new NorthAmericaCarFactory();
  CarFactory* europeFactory = new EuropeCarFactory();
  
  // Cars
  Car* northAmericaCar = northAmericaFactory->createCar();
  Car* europeCar = europeFactory->createCar();
  
  // Car specifications
  CarSpecification* northAmericaSpec = northAmericaFactory->createSpecification();
  CarSpecification* europeSpec = europeFactory->createSpecification();

  // Usage
  northAmericaCar->assemble();
  northAmericaSpec->display();

  europeCar->assemble();
  europeSpec->display();

  return 0;
}


/* 
Output

Assembling Sedan car.
North America Car Specification: Safety features compliant with local regulations.

Assembling Hatchback car.
Europe Car Specification: Fuel efficiency and emissions compliant wit...
*/