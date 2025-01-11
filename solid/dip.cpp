#include <iostream>
using namespace std;

class Toy {
  public:
    virtual void use() = 0;
};

// Different types of toys
class Lego : public Toy {
  public:
    void use() {
      cout << "kids is playing with lego";
    };
};

class PS5 : public Toy {};
class Gun : public Toy {};

// Client
class Kids {
  public:
    // depends on toy interface, not on a concreate toy
    void play(Toy* toy) {
      toy->use();
    }
};

int main() {
  Kids joe;
  Toy* lego = new Lego();
  
  joe.play(lego);
}