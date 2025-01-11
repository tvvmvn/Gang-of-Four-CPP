package oop.features;

// Abstract class
abstract class Animal {

  // Abstract method 
  public abstract void animalSound();
  
  // Normal method
  public void sleep() {
    System.out.println("Zzz");
  }
}

// Subclass 
class Pig extends Animal {

  // The body of animalSound() is provided here
  public void animalSound() {
    System.out.println("The pig says: wee wee");
  }
}

class _1_Abstraction {
  public static void main(String[] args) {

    Pig pig = new Pig(); 
    
    pig.animalSound();
    pig.sleep();
  }
}

// Output
// The pig says: wee wee
// Zzz