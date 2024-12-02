#include <iostream>
using namespace std;

// Abstract Class
class VehicleTemplate {
  public:
    // Template method: defines algorithm (structure)
    void buildVehicle() {
      assembleBody();
      installEngine();
      addWheels();
      
      cout << "Vehicle is ready!\n";
    }

    // Abstract methods: implemented by concrete classes
    virtual void assembleBody() = 0;
    virtual void installEngine() = 0;
    virtual void addWheels() = 0;
};

// Concrete Classes
class Car : public VehicleTemplate {
  public:
    void assembleBody() override {
      cout << "Assembling car body.\n";
    }

    void installEngine() override {
      cout << "Installing car engine.\n";
    }

    void addWheels() override {
      cout << "Adding 4 wheels to the car.\n";
    }
};

class Motorcycle : public VehicleTemplate {
  public:
    void assembleBody() override {
      cout << "Assembling motorcycle frame.\n";
    }

    void installEngine() override {
      cout << "Installing motorcycle engine.\n";
    }

    void addWheels() override {
      cout << "Adding 2 wheels to the motorcycle.\n";
    }
};

// Client Code
int main() {
  cout << "Building a Car:\n";
  Car car;
  car.buildVehicle();

  cout << "\nBuilding a Motorcycle:\n";
  Motorcycle motorcycle;
  motorcycle.buildVehicle();

  return 0;
}


/*
Output

Building a Car:
Assembling car body.
Installing car engine.
Adding 4 wheels to the car.
Vehicle is ready!

Building a Motorcycle:
Assembling motorcycle frame.
Installing motorcycle engine.
Adding 2 wheels to the motorcycle.
Vehicle is ready!
*/