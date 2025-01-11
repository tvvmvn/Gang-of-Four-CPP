#include <iostream>
#include <string>
using namespace std;

class Singleton {
  public:
    static Singleton* instance;

    static Singleton* getInstance() {
      if (!instance) { // set default value to instance
        cout << "An instance has been created" << endl;

        instance = new Singleton();
      }

      return instance;
    }

    void work() {
      cout << "It works" << endl;
    }
};

// initialize instance to nullptr
Singleton* Singleton::instance = nullptr;

int main() {
  Singleton* obj1 = Singleton::getInstance();
  Singleton* obj2 = Singleton::getInstance();

  obj1->work(); // It works
  obj2->work(); // It works
}