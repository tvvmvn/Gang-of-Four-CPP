package oop.relationships;

class Gasoline {

  void fill() {
     System.out.println("Gasoline has been filled");
  }
};

class Car {

  // Gasoline as parameters
  public void drive(Gasoline gasoline) {

    gasoline.fill();

    System.out.println("The car is running");
  }
};

public class _1_Dependency {
  public static void main(String[] args) {
    
    Gasoline gasoline = new Gasoline();

    Car car = new Car();

    car.drive(gasoline);
  }
}

// Output
// The car is running