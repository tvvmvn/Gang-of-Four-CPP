#include <iostream>
#include <string>
using namespace std;

// Base class is standard for making group of similar items.
class Animal {
  public:
    virtual string sound() = 0;
};

// A number of derived classes
class Dog : public Animal {
  public:
    string sound() {
      return "bow wow";
    }
};

class Cat : public Animal {
  public:
    string sound() {
      return "meow";
    }
};

class Pig : public Animal {
  public:
    string sound() {
      return "wee wee";
    }
};