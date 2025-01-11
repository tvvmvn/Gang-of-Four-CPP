package oop.elements;

class Calculator {

  public int add(int x, int y) {
    return x + y;
  }
}

public class _1_Message {
  public static void main(String[] args) {

    Calculator cal = new Calculator();

    // objects sends messages to other objects.
    // (Ask other objects to process tasks)
    int r = cal.add(1, 2);

    System.out.print("x + y = ");
    System.out.print(r);
  }
}

// Output
// x + y = 2