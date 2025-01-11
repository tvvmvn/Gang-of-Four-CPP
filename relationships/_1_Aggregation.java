package oop.relationships;

/*
In the UML, aggregation and composition are defined as 
special forms of associations with the intended meaning 
of classifying part-whole-relationships.
*/

// A printer can be shared with other computers.
class Printer {
  public String model;

  public Printer(String model) {
    this.model = model;
  }

  public String toString() {
    return String.format("[model='%s']", model);
  }
};

class Computer {
  public Printer printer;

  public Computer(Printer printer) {
    this.printer = printer;
  }

  // other parts..
};

public class _1_Aggregation {
  public static void main(String[] args) {
    
    Printer xerox = new Printer("P-115");

    Computer computer = new Computer(xerox);
    
    System.out.println(computer.printer);
  }
}

// Output
// [model='P-115']