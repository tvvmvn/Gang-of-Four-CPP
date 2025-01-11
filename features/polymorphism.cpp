#include <iostream>
#include <string>
using namespace std;

// Abstract class
class Animal {
  public:
    virtual void sound() = 0;
    // virtual destructor is not provided automatically.
    virtual ~Animal();
};

// Each derived class can implement different form of sound.
class Dog : public Animal {
  public:
    void sound() {
      cout << "bow wow" << endl;
    }
};

class Cat : public Animal {
  public:
    void sound() {
      cout << "meow" << endl;
    }
};

class Pig : public Animal {
  public:
    void sound() {
      cout << "wee wee" << endl;
    }
};

int main() {
  // Objects to be treated as instances of their parent class 
  // rather than their actual class.
  Animal* dog = new Dog();
  Animal* cat = new Cat();
  Animal* pig = new Pig();

  dog->sound();
  cat->sound();
  pig->sound();

  delete dog;
  delete cat;
  delete pig;
}

/*
Output

bow wow
meow
wee wee
*/