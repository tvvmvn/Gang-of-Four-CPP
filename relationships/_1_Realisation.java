package oop.relationships;

// Abstract class or interface(Java)
interface Flyable {
  public void fly();
};

// implementation
class Plane implements Flyable {

  public void fly() {
    System.out.println("It can fly with technology");
  }
};

// implementation
class Bird implements Flyable {

  public void fly() {
    System.out.println("It can fly with wings");
  }
};

public class _1_Realisation {
  public static void main(String[] args) {
    
    Flyable plane = new Plane();
    plane.fly();
    
    Flyable bird = new Bird();
    bird.fly();
  }
}

// Output
// It can fly with technology
// It can fly with wings