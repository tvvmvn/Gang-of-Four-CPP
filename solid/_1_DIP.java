package oop.solid;

interface Toy {
  public void use();
}

// Different types of toys
class Lego implements Toy {
  
  public void use() {
    System.out.println("kids is playing with lego");
  };
};

// Client
class Kids {

  // depends on toy interface, not on a concreate toy
  public void play(Toy toy) {
    toy.use();
  }
};

public class _1_DIP {
  public static void main(String[] args) {

    Toy lego = new Lego();
    Kids k = new Kids();
  
    k.play(lego);
  }
}
