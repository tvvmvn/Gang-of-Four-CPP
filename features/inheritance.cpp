#include <iostream>
#include <string>
using namespace std;

// Base class
class Car {
  public:
    string model;
    string motor;

    void run() {
      cout << "It is running";
    }
};

// Derived class
class KoreanCar : public Car {
  // no need to write again.
};

int main() {
  KoreanCar avanteHybrid;

  avanteHybrid.model = "Avante";
  avanteHybrid.motor = "Hybrid";
  avanteHybrid.run();
}

/*
Output

It is running
*/

