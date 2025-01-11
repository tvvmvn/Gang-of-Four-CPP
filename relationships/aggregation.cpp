#include <iostream>
#include <string>
using namespace std;

/*
In the UML, aggregation and composition are defined as 
special forms of associations with the intended meaning 
of classifying part-whole-relationships.
*/

// A printer can be shared with other computers.
class Printer {
  public:
    string model;
};

class Computer {
  public:
    Printer printer;
    // other parts..
};

int main() {};
