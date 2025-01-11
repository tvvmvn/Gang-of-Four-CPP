#include <iostream>
#include <string>
using namespace std;

/*
In the UML, aggregation and composition are defined as 
special forms of associations with the intended meaning 
of classifying part-whole-relationships.
*/

class Engine {};

class Car {
  public: 
    // to have exclusive (or non-shareable) parts.
    Engine engine;
};

int main() {};