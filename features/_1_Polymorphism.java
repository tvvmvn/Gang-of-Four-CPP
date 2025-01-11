package oop.features;

class Animal {
  public void sound() {
    System.out.println("The animal makes a sound");
  }
}

class Dog extends Animal {
  public void sound() {
    System.out.println("bow wow");
  }
}

class Cat extends Animal {
  public void sound() {
    System.out.println("meow");
  }
}

class Pig extends Animal {
  public void sound() {
    System.out.println("wee wee");
  }
}

public class _1_Polymorphism {
  public static void main(String[] args) {
    // Objects to be treated as instances of their parent class 
    // rather than their actual class.
    Animal dog = new Dog();
    dog.sound();

    Animal cat = new Cat();
    cat.sound();
    
    Animal pig = new Pig();    
    pig.sound();
  }
}


// Output
// bow wow
// meow
// wee wee