package oop.relationships;

class Coffee {

  public String beans;

  public Coffee(String beans) {
    this.beans = beans;
  }

  public String toString() {
    return String.format("Americano[beans='%s']", beans);
  }
}

// These are types of coffee.
class Americano extends Coffee {

  public String water;

  public Americano(String beans, String water) {
    
    super(beans);
    this.water = water;
  }

  @Override
  public String toString() {
    return String.format("Americano[beans='%s', water='%s']", beans, water);
  }
};

class Latte extends Coffee {
  
  public String water;
  public String milk;

  public Latte(String beans, String water, String milk) {
    
    super(beans);
    this.water = water;
    this.milk = milk;
  }

  @Override
  public String toString() {
    return String.format("Americano[beans='%s', water='%s', milk='%s']", beans, water, milk);
  }
};

public class _1_Generalisation {
  public static void main(String[] args) {

    // Generalisation
    Coffee americano = new Americano("Columbia", "2l");
    Coffee latte = new Latte("Columbia", "2l", "Milk");

    System.out.println(americano);
    System.out.println(latte);
  }
}

// Output
// Americano[beans='Columbia', water='2l']
// Americano[beans='Columbia', water='2l', milk='Milk']