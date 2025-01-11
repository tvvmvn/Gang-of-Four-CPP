package oop.features;

class Vehicle {
  public void honk() {                    
    System.out.println("Tuut, tuut!");
  }
}

class Car extends Vehicle {
  public String model = "Mustang";
}

public class _1_Inheritance {
  public static void main(String[] args) {
  
    Car myCar = new Car();
  
    myCar.honk();
  }
}