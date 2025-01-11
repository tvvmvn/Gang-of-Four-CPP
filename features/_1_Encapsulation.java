package oop.features;

class Capsule {
  
  // only accessible in this class
  private String name; 
  
  // Getter
  public String getName() {
    return name;
  }
  
  // Setter
  public void setName(String name) {
    this.name = name;
  }
}

public class _1_Encapsulation {
  public static void main(String[] args) {
    
    Capsule capsule = new Capsule();

    capsule.setName("John");

    System.out.println(capsule.getName());
  }
}

// Output
// John