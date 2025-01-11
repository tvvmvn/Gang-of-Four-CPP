package oop.solid;

// A fat interface
interface MFP {
  public void print();
  public void scan();
  public void fax();
};

// Break down the MFP interface into smaller interfaces.
interface Printer {
  public void print();
};

interface Scanner {
  public void scan();
};

interface Fax {
  public void fax();
};

// Concrete class
class MyPrinter implements Printer {
  public void print() {
    System.out.println("It is printing a document.");
  }
}

public class _1_ISP {
  public static void main(String[] args) {
    
  }
}