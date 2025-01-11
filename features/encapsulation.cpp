#include <iostream>
#include <string>
using namespace std;

class Employee {
  private:
    int salary;

  public:
    // setter
    void setSalary(int a) {
      salary = a;
    } 
    // getter
    int getSalary() {
      return salary;
    }
};

int main() {
  Employee john;

  john.setSalary(500);

  cout << john.getSalary(); 
}

/*
Output
500
*/