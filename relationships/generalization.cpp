#include <iostream>
#include <string>
using namespace std;

// General
class Coffee {
  public:
    string espresso;
};

// These are types of coffee.
class Americano : public Coffee {
  public:
    string water;
};

class Latte : public Coffee {
  public:
    string water;
    string milk;
};

