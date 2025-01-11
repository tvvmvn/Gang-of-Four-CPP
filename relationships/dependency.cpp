#include <iostream>
#include <string>
using namespace std;

class Gasoline {};

class Car {
  public:
    // Gasoline as parameters
    void drive(Gasoline gasoline) {}
};

int main() {};