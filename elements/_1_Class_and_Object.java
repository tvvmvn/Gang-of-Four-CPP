package oop.elements;

// Class
class Car {
  // Attributes
  public String engine;

  // Operation 
  public void run() {
    System.out.println("Running powered by " + engine);
  }
}

public class _1_Class_and_Object {
  public static void main(String[] args) {

    // Instances of Car
    Car avante = new Car();
    avante.engine = "Gasoline";
    avante.run();
    
    Car xm3Hybrid = new Car();
    xm3Hybrid.engine = "Hybrid";
    xm3Hybrid.run();
  }
}

// Output
// Running powered by Gasoline
// Running powered by Hybrid